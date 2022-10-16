#include <vector>
#include <cstdio>
const int Maxn=100000;
int n,m;
std::vector<int> lis[Maxn+5];
int num[Maxn+5];
bool vis[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		num[i]=0;
	}
	for(int i=1;i<=m;i++){
		vis[i]=0;
		lis[i].clear();
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			lis[i].push_back(x);
		}
		num[lis[i][0]]++;
	}
	int pos=-1;
	for(int i=1;i<=n;i++){
		if(num[i]>((m+1)>>1)){
			pos=i;
			break;
		}
	}
	if(pos==-1){
		puts("YES");
		for(int i=1;i<=m;i++){
			printf("%d ",lis[i][0]);
		}
		puts("");
	}
	else{
		for(int i=1;i<=m&&num[pos]>((m+1)>>1);i++){
			if(lis[i][0]==pos&&(int)lis[i].size()>1){
				vis[i]=1;
				num[pos]--;
				num[lis[i][1]]++;
			}
		}
		if(num[pos]>((m+1)>>1)){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=1;i<=m;i++){
				if(vis[i]){
					printf("%d ",lis[i][1]);
				}
				else{
					printf("%d ",lis[i][0]);
				}
			}
			puts("");
		}
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