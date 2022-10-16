#include <cstdio>
#define Maxn 100
int n,m,k;
char mp[Maxn+5][Maxn+5];
char ans[Maxn+5][Maxn+5];
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const char c[65]={"0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
int main(){
	int t;
	scanf("%d",&t);
	int num;
	int use;
	int last;
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		num=0;
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++){
				if(mp[i][j]=='R'){
					num++;
				}
			}
		}
		use=num/k;
		last=0;
		for(int i=1,col=0;i<=n;i++){
			for(int j=((i&1)?1:m);((i&1)?j<=m:j>0);((i&1)?j++:j--)){
				ans[i][j]=c[col];
				if(mp[i][j]=='R'){
					last++;
				}
				if(last==use){
					last=0;
					num-=use;
					col++;
					if(col==k){
						col--;
						continue;
					}
					if(num/(k-col)!=use){
						use=num/(k-col);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				putchar(ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}