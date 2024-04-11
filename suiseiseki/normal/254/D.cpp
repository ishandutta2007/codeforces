#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 1000
#define Maxm 290
struct Node{
	int x,y,d;
	Node(int _x=0,int _y=0,int _d=0){
		x=_x;
		y=_y;
		d=_d;
	}
};
vector<Node> rats;
int n,m,d,cnt_rats=0,size=0;
int map[Maxn+5][Maxn+5];
char s[Maxn+5][Maxn+5];
int reach[Maxn+5][Maxn+5];
int vx[Maxm*Maxm+5],vy[Maxm*Maxm+5];
bool va[Maxm*Maxm+5][Maxm+5];
bool vis[Maxn+5][Maxn+5];
const int _d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void put_set(int x,int y,int type){
	if(!reach[x][y]){
		va[++size][type]=1;
		vx[size]=x;
		vy[size]=y;
		return;
	}
	for(int i=1;i<=size;i++){
		if(vx[i]==x&&vy[i]==y){
			va[i][type]=1;
			break;
		}
	}
}
queue<Node> q;
void bfs(int type,Node st){
	memset(vis,0,sizeof vis);
	while(!q.empty()){
		q.pop();
	}
	q.push(st);
	vis[st.x][st.y]=1;
	Node u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		put_set(u.x,u.y,type);
		reach[u.x][u.y]=1;
		if(u.d==d){
			continue;
		}
		for(int i=0;i<4;i++){
			v.x=u.x+_d[i][0];
			v.y=u.y+_d[i][1];
			v.d=u.d+1;
			if(v.x<1||v.x>n||v.y<1||v.y>m||vis[v.x][v.y]||map[v.x][v.y]){
				continue;
			}
			vis[v.x][v.y]=1;
			q.push(v);
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ans1,ans2,find_ans=0;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='R'){
				cnt_rats++;
			}
		}
	}
	if(cnt_rats>Maxm){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=0;
			if(s[i][j]=='X'){
				map[i][j]=1;
			}
			if(s[i][j]=='R'){
				rats.push_back(Node(i,j,0));
			}
		}
	}
	for(int i=0;i<cnt_rats;i++){
		bfs(i,rats[i]);
	}
	if(size==1){
		for(int i=0;i<cnt_rats;i++){
			if(va[1][i]==0){
				puts("-1");
				return 0;
			}
		}
		printf("%d %d ",vx[1],vy[1]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j]||(i==vx[1]&&j==vy[1])){
					continue;
				}
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	for(int i=1;i<size;i++){
		for(int j=i+1;j<=size;j++){
			find_ans=1;
			for(int k=0;k<cnt_rats;k++){
				if(va[i][k]==0&&va[j][k]==0){
					find_ans=0;
					break;
				}
			}
			if(find_ans){
				ans1=i;
				ans2=j;
				break;
			}
		}
		if(find_ans){
			break;
		}
	}
	if(find_ans){
		printf("%d %d %d %d\n",vx[ans1],vy[ans1],vx[ans2],vy[ans2]);
	}
	else{
		puts("-1");
	}
	return 0;
}