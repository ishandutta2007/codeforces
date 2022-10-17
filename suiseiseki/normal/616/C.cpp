#include <cstdio>
int number[1000005];
int n,m;
int of[1005][1005];
char mp[1005][1005];
bool visit[1005][1005];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y,int now){
	of[x][y]=now;
	number[now]++;
	visit[x][y]=1;
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=x+d[i][0];
		ny=y+d[i][1];
		if(nx<1||ny<1||nx>n||ny>m||visit[nx][ny]||mp[nx][ny]=='*'){
			continue;
		}
		dfs(nx,ny,now);
	}
}
bool use[1000005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='*'||visit[i][j]){
				continue;
			}
			dfs(i,j,++tot);
		}
	}
	int ans;
	int nx,ny;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='*'){
				ans=0;
				for(int k=0;k<4;k++){
					nx=i+d[k][0];
					ny=j+d[k][1];
					if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='#'){
						continue;
					}
					if(!use[of[nx][ny]]){
						use[of[nx][ny]]=1;
						ans+=number[of[nx][ny]];
					}
				}
				for(int k=0;k<4;k++){
					nx=i+d[k][0];
					ny=j+d[k][1];
					if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='#'){
						continue;
					}
					use[of[nx][ny]]=0;
				}
				printf("%d",(ans+1)%10);
			}
			else{
				putchar('.');
			}
		}
		puts("");
	}
	return 0;
}