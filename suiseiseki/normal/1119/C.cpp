#include <cstdio>
#define Maxn 500
int mp[Maxn+5][Maxn+5];
int to[Maxn+5][Maxn+5];
int n,m;
int row[Maxn+5],line[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&to[i][j]);
			if(mp[i][j]!=to[i][j]){
				row[i]++;
				line[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(row[i]&1){
			puts("No");
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(line[i]&1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}