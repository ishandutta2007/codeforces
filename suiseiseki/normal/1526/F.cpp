#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>
const int Maxn=100000;
int n;
int query(int a,int b,int c){
	printf("? %d %d %d\n",a,b,c);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
std::vector<int> lis[Maxn+5];
int ans[Maxn+5];
void solve(){
	scanf("%d",&n);
	int a,b,c;
	bool flag=0;
	for(int i=1;i<=13;i++){
		for(int j=i+1;j<=13;j++){
			for(int k=j+1;k<=13;k++){
				if(query(i,j,k)<=(n-4)/6){
					a=i,b=j,c=k;
					flag=1;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		lis[i].clear();
	}
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b){
			lis[query(a,b,i)].push_back(i);
		}
	}
	int maxn=0;
	for(int i=n;i>0;i--){
		if(!lis[i].empty()){
			maxn=i;
			break;
		}
	}
	if(lis[maxn-1].size()>=2){
		if(query(lis[maxn][0],lis[maxn-1][0],a)>query(lis[maxn][0],lis[maxn-1][1],a)){
			std::swap(lis[maxn-1][0],lis[maxn-1][1]);
		}
	}
	a=lis[maxn][0],b=lis[maxn-1][0];
	ans[a]=1,ans[b]=2;
	for(int i=1;i<=n;i++){
		if(i==a||i==b){
			continue;
		}
		ans[i]=query(a,b,i)+2;
	}
	if(ans[1]>ans[2]){
		for(int i=1;i<=n;i++){
			ans[i]=n-ans[i]+1;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	fflush(stdout);
	scanf("%d",&c);
	assert(c==1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}