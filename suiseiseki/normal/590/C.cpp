/*#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
char mp[1005][1005];
struct Node{
	int x,y;
	int v;
};
int mn(int a,int b){
	return a<b?a:b;
}
deque<Node> q;
int ans[1005][1005][8];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int sx,int sy){
	memset(ans,0x7f,sizeof ans);
	Node x,now;
	x.x=sx;
	x.y=sy;
	x.v=0;
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=sx+d[i][0];
		ny=sy+d[i][1];
		if(nx<1||ny<1||nx>n||ny>m){
			continue;
		}
		if(mp[nx][ny]>'0'&&mp[nx][ny]<'4'){
			x.v|=(1<<(mp[nx][ny]-'1'));
		}
	}
	ans[sx][sy][x.v]=0;
	q.push_back(x);
	while(!q.empty()){
		x=q.front();
		q.pop_front();
		for(int i=0;i<4;i++){
			now.x=x.x+d[i][0];
			now.y=x.y+d[i][1];
			now.v=x.v;
			if(now.x<1||now.y<1||now.x>n||now.y>m||mp[now.x][now.y]=='#'){
				continue;
			}
			for(int j=0;j<4;j++){
				nx=now.x+d[j][0];
				ny=now.y+d[j][1];
				if(nx<1||ny<1||nx>n||ny>m){
					continue;
				}
				if(mp[nx][ny]>'0'&&mp[nx][ny]<'4'){
					now.v|=(1<<(mp[nx][ny]-'1'));
				}
			}
			if(mp[now.x][now.y]>'0'&&mp[now.x][now.y]<'4'){
				if(ans[now.x][now.y][now.v]>ans[x.x][x.y][x.v]){
					ans[now.x][now.y][now.v]=ans[x.x][x.y][x.v];
					q.push_back(now);
				}
			}
			else{
				if(ans[now.x][now.y][now.v]>ans[x.x][x.y][x.v]+1){
					ans[now.x][now.y][now.v]=ans[x.x][x.y][x.v]+1;
					q.push_back(now);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int now=0;
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]>'0'&&mp[i][j]<'4'){
				now|=(1<<(mp[i][j]-'1'));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]>'0'||mp[i][j]<'4'){
				bfs(i,j);
			}
		}
	}
	int answer=0x7f7f7f7f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			answer=mn(answer,ans[i][j][now]);
		}
	}
	if(answer==0x7f7f7f7f){
		puts("-1");
	}
	else{
		printf("%d\n",answer);
	}
	return 0;
}*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1005;
const int Inf=0x3f3f3f3f;
const int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
typedef pair<int,int> pii;
int N,M,V[4][maxn][maxn],K;
char G[maxn][maxn];
void bfs(int s,int d[maxn][maxn]){
    queue<pii> que;
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=M;j++){
			if(G[i][j]=='0'+s){
            	d[i][j]=0;
            	que.push(make_pair(i,j));
            }
        }
	}
    if(!que.empty()){
    	K++;
	}
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int p=x+dir[i][0];
            int q=y+dir[i][1];
            if(p<=0||p>N||q<=0||q>M){
            	continue;
			}
            if(G[p][q]=='#'){
            	continue;
			}
            if(d[p][q]>d[x][y]+1){
                d[p][q]=d[x][y]+1;
                que.push(make_pair(p,q));
            }
        }
    }
}
int solve(){
    if(K<=1){
    	return 0;
	}
    vector<int> tmp;
    tmp.clear();
    for(int x=1;x<=K;x++){
        for(int y=x+1;y<=K;y++){
            int ret=Inf;
            for(int i=1;i<=N;i++){
                for(int j=1;j<=M;j++){
                    if(G[i][j]=='0'+y){
                    	ret=min(ret,V[x][i][j]);
					}
                }
            }
            tmp.push_back(ret);
        }
    }
    sort(tmp.begin(),tmp.end());
    if(tmp[0]==Inf){
    	return Inf;
    }
    if(K==2){
    	return tmp[0]-1;
	}
    if(tmp[1]==Inf){
    	return Inf;
	}
    return tmp[0]+tmp[1]-2;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
    	scanf("%s",G[i]+1);
	}
    memset(V,Inf,sizeof(V));
    for(int i=1;i<=3;i++){
    	bfs(i,V[i]);
	}
    int ans=solve();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(G[i][j]!='.'){
            	continue;
			}
            int tmp=0;
            for(int k=1;k<=K;k++){
                if(V[k][i][j]==Inf){
                    tmp=Inf;
                    break;
                }
                tmp+=V[k][i][j];
            }
            if(tmp==Inf){
            	continue;
			}
            ans=min(ans,tmp-K+1);
        }
    }
    if(ans==Inf){
    	ans=-1;
	}
    printf("%d\n",ans);
    return 0;
}