#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=2000;
int n,k;
char s_a[Maxn+5],s_b[Maxn+5];
int a[Maxn+5],b[Maxn+5];
int num;
std::pair<int,int> work(int l,int x,int *a){
	int r=l+k,y=a[l]+a[r]-x;
	int sum_l,sum_r;
	if(x<0){
		x=a[l]+a[r];
		y=0;
	}
	if(x<=a[l]){
		sum_l=l+x;
		for(int i=0;i<l;i++){
			sum_l+=a[i];
		}
		sum_r=r-1;
		for(int i=0;i<r;i++){
			sum_r+=a[i];
		}
	}
	else{
		sum_l=l;
		for(int i=0;i<=l;i++){
			sum_l+=a[i];
		}
		sum_r=r-y-1;
		for(int i=0;i<=r;i++){
			sum_r+=a[i];
		}
	}
	a[l]=x,a[r]=y;
	std::reverse(a+1+l,a+r);
	return std::make_pair(sum_l,sum_r);
}
void work_way(char *s,int *r){
	int x=0,l=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			r[l++]=x;
			x=0;
		}
		else{
			x++;
		}
	}
	r[l]=x;
}
std::vector<std::pair<int,int> > get_ans(int *a){
	std::vector<std::pair<int,int> > ans;
	if(k&1){
		for(int i=0;i<=num-k;i++){
			ans.push_back(work(i,0,a));
		}
		for(int i=1;i<k;i++){
			ans.push_back(work(num-k-1,0,a));
			ans.push_back(work(num-k,0,a));
		}
	}
	else{
		for(int i=0;i<=num-k;i++){
			ans.push_back(work(i,0,a));
		}
		for(int i=2;i<k;i+=2){
			ans.push_back(work(num-k-1,-1,a));
			ans.push_back(work(num-k,0,a));
		}
		ans.push_back(work(num-k-1,0,a));
	}
	return ans;
}
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s_a);
	scanf("%s",s_b);
	num=0;
	bool flag=1;
	for(int i=0;i<n;i++){
		num+=(s_a[i]=='1');
		if(s_a[i]!=s_b[i]){
			flag=0;
		}
	}
	if(flag){
		puts("0");
		return;
	}
	if(k==0||k>num){
		puts("-1");
		return;
	}
	{
		int num_c=0;
		for(int i=0;i<n;i++){
			num_c+=(s_b[i]=='1');
		}
		if(num_c!=num){
			puts("-1");
			return;
		}
	}
	work_way(s_a,a);
	work_way(s_b,b);
	if(num==k){
		if(a[0]+a[num]!=b[0]+b[num]){
			puts("-1");
			return;
		}
		std::pair<int,int> tmp_1=work(0,b[0],a);
		if(!memcmp(a+1,b+1,(num-1)*(sizeof(int)))){
			puts("1");
			printf("%d %d\n",tmp_1.first+1,tmp_1.second+1);
			return;
		}
		std::pair<int,int> tmp_2=work(0,b[0],a);
		if(!memcmp(a+1,b+1,(num-1)*(sizeof(int)))){
			puts("2");
			printf("%d %d\n",tmp_1.first+1,tmp_1.second+1);
			printf("%d %d\n",tmp_2.first+1,tmp_2.second+1);
			return;
		}
		puts("-1");
		return;
	}
	std::vector<std::pair<int,int> > lis_1=get_ans(a),lis_2=get_ans(b);
	if(memcmp(a,b,(num+1)*(sizeof(int)))){
		puts("-1");
		return;
	}
	std::reverse(lis_2.begin(),lis_2.end());
	printf("%d\n",lis_1.size()+lis_2.size());
	for(int i=0;i<(int)lis_1.size();i++){
		printf("%d %d\n",lis_1[i].first+1,lis_1[i].second+1);
	}
	for(int i=0;i<(int)lis_2.size();i++){
		printf("%d %d\n",lis_2[i].first+1,lis_2[i].second+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}