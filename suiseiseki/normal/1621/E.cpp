#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n,m;
int a[Maxn+5];
int sz[Maxn+5],id[Maxn+5];
ll sum[Maxn+5];
std::vector<int> lis[Maxn+5];
std::vector<int> ans[Maxn+5];;
int s[Maxn+5][3];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n);
	std::reverse(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d",&sz[i]);
		sum[i]=0;
		lis[i].resize(sz[i]);
		ans[i].resize(sz[i]);
		for(int j=0;j<sz[i];j++){
			scanf("%d",&lis[i][j]);
			sum[i]+=lis[i][j];
			ans[i][j]=0;
		}
		id[i]=i;
	}
	std::sort(id+1,id+1+m,[&](int p,int q){
		return sum[p]*sz[q]>sum[q]*sz[p];
	});
	a[0]=a[1];
	for(int I=1;I<=m;I++){
		int i=id[I];
		s[I][0]=s[I-1][0],s[I][1]=s[I-1][1],s[I][2]=s[I-1][2];
		if(sum[i]<=1ll*a[I-1]*sz[i]){
			s[I][0]++;
		}
		if(sum[i]<=1ll*a[I]*sz[i]){
			s[I][1]++;
		}
		if(sum[i]<=1ll*a[I+1]*sz[i]){
			s[I][2]++;
		}
	}
	for(int I=1;I<=m;I++){
		int i=id[I];
		for(int j=0;j<(int)lis[i].size();j++){
			ll cur_s=sum[i]-lis[i][j];
			if(cur_s>1ll*a[1]*(sz[i]-1)){
				ans[i][j]=0;
				continue;
			}
			int left=1,right=m;
			while(left<right){
				int mid=(left+right+1)>>1;
				if(cur_s<=1ll*a[mid]*(sz[i]-1)){
					left=mid;
				}
				else{
					right=mid-1;
				}
			}
			if(left>=I){
				if(s[left][0]-s[I][0]+1+s[m][1]-s[left][1]+s[I-1][1]==m){
					ans[i][j]=1;
				}
				else{
					ans[i][j]=0;
				}
			}
			else{
				if(s[I-1][2]-s[left-1][2]+1+s[left-1][1]+s[m][1]-s[I][1]==m){
					ans[i][j]=1;
				}
				else{
					ans[i][j]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j:ans[i]){
			printf("%d",j);
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}