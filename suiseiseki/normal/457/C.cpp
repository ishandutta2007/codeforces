#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Inf (1<<30)
#define Maxn 100000
#define Maxm 10000
int a[Maxn+5],b[Maxn+5];
int n;
vector<int> x[Maxn+5],y[Maxn+5];
int dy[Maxn+5];
bool cmp(int p,int q){
	return y[p].size()<y[q].size();
}
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int f_num[Maxm+5],f_sum[Maxm+5];
void add(int x,int a){
	if(x==0){
		f_num[0]++;
		f_sum[0]+=a;
		x++;
	}
	for(int i=x;i<=Maxm;i+=(i&(-i))){
		f_num[i]++;
		f_sum[i]+=a;
	}
}
int q_num(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f_num[i];
	}
	ans+=f_num[0];
	return ans;
}
int q_sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f_sum[i];
	}
	ans+=f_sum[0];
	return ans;
}
bool cmp_greater(int p,int q){
	return p>q;
}
int main(){
	scanf("%d",&n);
	int minn=Inf,minn_tmp;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]==0){
			a[i]=0;
		}
		if(b[i]<minn){
			minn=b[i];
			minn_tmp=a[i];
		}
		y[a[i]].push_back(b[i]);
	}
	if(y[0].empty()){
		y[0].push_back(minn);
		sort(y[minn_tmp].begin(),y[minn_tmp].end(),cmp_greater);
		y[minn_tmp].pop_back();
	}
	else{
		minn=0;
	}
	for(int i=1;i<=Maxn;i++){
		dy[i]=i;
	}
	for(int i=1;i<=Maxn;i++){
		sort(y[i].begin(),y[i].end());
	}
	sort(dy+1,dy+1+Maxn,cmp);
	for(int i=0;i<=Maxn;i++){
		x[i]=y[dy[i]];
	}
	int now=1;
	while(now<=Maxn&&((int)x[now].size()<(int)x[0].size()||x[now].empty())){
		now++;
	}
	for(int i=1;i<now;i++){
		for(int j=0;j<(int)x[i].size();j++){
			add(x[i][j],x[i][j]);
		}
	}
	int sum=0;
	int tot=0;
	for(int i=now;i<=Maxn;i++){
		for(int j=0;j<(int)x[i].size()-mx((int)x[0].size(),1)+1;j++){
			sum+=x[i][j];
			tot++;
		}
		for(int j=(int)x[i].size()-mx((int)x[0].size(),1)+1;j<(int)x[i].size();j++){
			add(x[i][j],x[i][j]);
		}
	}
	int ans=Inf;
	int left,right,mid;
	int sum_2;
	for(int i=(int)x[0].size();i<=n;i++){
		while(now<=Maxn&&(int)x[now].size()<i){
			now++;
		}
		if((int)x[0].size()+tot>=i){
			ans=mn(ans,sum);
		}
		else{
			left=0,right=Maxm;
			while(left<right){
				mid=(left+right)>>1;
				if((int)x[0].size()+tot+q_num(mid)>=i){
					right=mid;
				}
				else{
					left=mid+1;
				}
			}
			sum_2=q_sum(left)-((int)x[0].size()+tot+q_num(left)-i)*left;
			ans=mn(ans,sum+sum_2);
		}
		for(int j=now;j<=Maxn;j++){
			tot--;
			if((int)x[j].size()-i>=0&&(int)x[j].size()-i<(int)x[j].size()){
				sum-=x[j][(int)x[j].size()-i];
				add(x[j][(int)x[j].size()-i],x[j][(int)x[j].size()-i]);
			}
		}
	}
	printf("%d\n",ans+minn);
	return 0;
}