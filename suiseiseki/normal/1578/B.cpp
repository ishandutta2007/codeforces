#include <cstdio>
#include <algorithm>
const int Maxn=400;
int n,m;
int s[Maxn+5][Maxn+5],ans;
char st[Maxn+5][Maxn+5];
int find_sum(int i,int j,int x,int y){
	return s[x][y]-s[x][j-1]-s[i-1][y]+s[i-1][j-1];
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",st[i]+1);
		for(int j=1;j<=m;j++){
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+st[i][j]-'0';
		}
	}
	ans=16;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int a=5;i+a-1<=n;a++){
				for(int b=4;j+b-1<=m;b++){
					int num=find_sum(i+1,j+1,i+a-2,j+b-2)+a+b-4-find_sum(i+1,j,i+a-2,j)-find_sum(i,j+1,i,j+b-2);
					if(num>=ans){
						break;
					}
					num+=a+b-4-find_sum(i+a-1,j+1,i+a-1,j+b-2)-find_sum(i+1,j+b-1,i+a-2,j+b-1);
					ans=std::min(ans,num);
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}