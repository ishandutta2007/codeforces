#include <cstdio>
const int Maxn=1000;
const int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
const char c_1[4]={'R','L','U','D'},c_2[4]={'L','R','D','U'};
int n;
int x[Maxn+5][Maxn+5],y[Maxn+5][Maxn+5];
char mp[Maxn+5][Maxn+5];
bool vis[Maxn+5][Maxn+5];
bool work_dfs(int u_x,int u_y,int last,bool found){
	vis[u_x][u_y]=1;
	if(found){
		mp[u_x][u_y]=c_2[last];
	}
	for(int i=0;i<4;i++){
		int v_x=u_x+d[i][0],v_y=u_y+d[i][1];
		if(v_x<1||v_y<1||v_x>n||v_y>n||x[v_x][v_y]==-1||y[v_x][v_y]==-1){
			continue;
		}
		if(x[v_x][v_y]!=x[u_x][u_y]||y[v_x][v_y]!=y[u_x][u_y]||vis[v_x][v_y]||(mp[v_x][v_y]!='\0')){
			continue;
		}
		if(found){
			work_dfs(v_x,v_y,i,1);
		}
		else{
			if(work_dfs(v_x,v_y,i,0)){
				found=1;
				mp[u_x][u_y]=c_1[i];
			}
		}
	}
	if(!found){
		mp[u_x][u_y]=c_2[last];
	}
	return found;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d%d",&x[i][j],&y[i][j]);
			if(x[i][j]!=-1&&y[i][j]!=-1){
				mp[x[i][j]][y[i][j]]='X';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='X'){
				if(x[i][j]==-1){
					puts("INVALID");
					return 0;
				}
				if(x[i][j]!=i||y[i][j]!=j){
					puts("INVALID");
					return 0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='X'){
				work_dfs(i,j,0,1);
				mp[i][j]='X';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]==-1&&mp[i][j]=='\0'){
				int to=-1;
				int nx,ny;
				for(int k=0;k<4;k++){
					nx=i+d[k][0],ny=j+d[k][1];
					if(nx<1||ny<1||nx>n||ny>n||x[nx][ny]!=-1){
						continue;
					}
					to=k;
				}
				if(to==-1){
					puts("INVALID");
					return 0;
				}
				mp[i][j]=c_1[to];
				if(mp[nx][ny]=='\0'){
					mp[nx][ny]=c_2[to];
				}
			}
			else if(x[i][j]!=-1&&mp[i][j]=='\0'){
				puts("INVALID");
				return 0;
			}
		}
	}
	puts("VALID");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			putchar(mp[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
5
1 1 1 1 1 1 2 4 2 4
1 1 2 2 1 1 2 4 2 4
-1 -1 1 1 1 1 5 5 5 5
-1 -1 1 1 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5 5
*/