#include <cstdio>
int mp[105][105];
int n,m;
bool check_row(int row){
	for(int i=2;i<=m;i++){
		if(mp[row][i]!=mp[row][i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&mp[i][j]);
		}
		if(!check_row(i)){
			puts("NO");
			return 0;
		}
		if(i>1&&mp[i][1]==mp[i-1][1]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}