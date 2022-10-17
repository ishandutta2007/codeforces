#include <cstdio>
char mp[1005][1005];
int n,m;
const char d[3][3]={'#','#','#','#','.','#','#','#','#'};
bool get_ans;
void dfs(int x,int y){
	if(y>m){
		x++;
		y=1;
	}
	if(x>n){
		get_ans=1;
		return;
	}
	char cz[3][3];
	if(mp[x][y]=='#'||mp[x][y]=='?'){
		if(x+2>n||y+2>m){
			if(mp[x][y]=='#'){
				return;
			}
			else{
				dfs(x,y+1);
				return;
			}
		}
		if(mp[x][y+1]=='.'||mp[x][y+2]=='.'||mp[x+1][y]=='.'||mp[x+1][y+2]=='.'||mp[x+2][y]=='.'||mp[x+2][y+1]=='.'||mp[x+2][y+2]=='.'){
			if(mp[x][y]=='#'){
				return;
			}
			else{
				dfs(x,y+1);
				return;
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cz[i][j]=mp[x+i][y+j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==1&&j==1){
					continue;
				}
				mp[x+i][y+j]='?';
			}
		}
		dfs(x,y+1);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				mp[x+i][y+j]=cz[i][j];
			}
		}
		if(get_ans){
			return;
		}
	}
	dfs(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	dfs(1,1);
	if(get_ans){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}
/////////////