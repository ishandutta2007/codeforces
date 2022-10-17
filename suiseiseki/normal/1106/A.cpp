#include <cstdio>
#define Maxn 500
char mp[Maxn+5][Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='X'&&mp[i-1][j-1]=='X'&&mp[i-1][j+1]=='X'&&mp[i+1][j-1]=='X'&&mp[i+1][j+1]=='X'){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}