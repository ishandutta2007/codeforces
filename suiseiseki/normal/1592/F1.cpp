#include <cstdio>
const int Maxn=500;
int n,m;
int a[Maxn+5][Maxn+5];
char s[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=(s[i][j]=='B');
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]^=a[i+1][j]^a[i][j+1]^a[i+1][j+1];
			if(a[i][j]){
				ans++;
			}
		}
	}
	bool flag=0;
	if(a[n][m]){
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(a[i][j]&&a[n][j]&&a[i][m]){
					flag=1;
				}
			}
		}
	}
	if(flag){
		ans--;
	}
	printf("%d\n",ans);
	return 0;
}