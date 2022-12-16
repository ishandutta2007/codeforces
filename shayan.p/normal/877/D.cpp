#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1010;
char c[maxn][maxn];
ll depth[maxn][maxn],mark[5][maxn][maxn],vis[maxn][maxn],n,m,k;
ll dx[5],dy[5];
queue<pll>q;
int main(){
	dx[0]=0;dx[1]=1;dx[2]=0;dx[3]=-1;
	dy[0]=1;dy[1]=0;dy[2]=-1;dy[3]=0;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
		cin>>c[i][j];
	ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	if(x1==x2&&y1==y2){
		cout<<0;
		exit(0);
	}
	q.push(MP(x1,y1));
	vis[x1][y1]=1;
	while(q.size()){
		pll p=q.front();q.pop();
		for(ll i=0;i<4;i++){
			for(ll j=1;j<=k;j++){
				ll x=p.F+dx[i]*j,y=p.S+dy[i]*j;
				if(c[x][y]!='.'||mark[i][x][y])break;
				mark[i][x][y]=1;
				vis[x][y]=1;
				depth[x][y]=depth[p.F][p.S]+1;
				q.push(MP(x,y));
				if(x==x2&&y==y2){
					cout<<depth[x][y];
					exit(0);
				}
			}
		}
	}
	cout<<-1;
}