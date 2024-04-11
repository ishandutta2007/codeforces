#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
//#define endl "\n"
const ll MAX = 25e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,m,p;
inline bool inside(int rr,int cc){
	return rr>0&&cc>0&&rr<=n&&cc<=m;
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>p;
    if(n==1&&m==1)return cout<<0,0;
	int vis[301][301],r,c,nw,x,y[301][301],nr,nc;
	vector<pii> v[90001];
	priority_queue<piiii, vector<piiii>, greater<piiii> > pq;
	piiii cur;
	int st;
	bool visi[301][301];
	rep(i,1,n)rep(j,1,m)cin>>x, v[x].pb({i,j}), vis[i][j] = 1e9, y[i][j] = x;
    for(auto i:v[1])pq.push({{2,(i.fi-1)+(i.se-1)},{i.fi,i.se}}),vis[i.fi][i.se]=(i.fi-1)+(i.se-1);
    while(!pq.empty()){
    	cur = pq.top(); pq.pop();
    	nw = cur.ff, x = cur.fs, r = cur.sf, c = cur.ss;
    	if(nw>p)break;
    	if(v[nw].size()<9000){
    		if(vis[r][c]<x)continue;
	    	for(auto i:v[nw]){
	    		st = nw;
	    		if(vis[i.fi][i.se]<=x+abs(i.fi-r)+abs(i.se-c))continue;
	    		vis[i.fi][i.se] = x+abs(i.fi-r)+abs(i.se-c);
	    		pq.push({{nw+1,x+abs(i.fi-r)+abs(i.se-c)},{i.fi,i.se}});
			}
		}
		else {
			if(st!=nw){
				memset(visi,0,sizeof visi);
				st = nw;
			}
			visi[r][c] = 1;
			rep(k,0,3){
				nr = r+dr[k], nc = c+dc[k];
				if(!inside(nr,nc))continue;
				if(visi[nr][nc])continue;
				visi[nr][nc] = 1;
				if(y[nr][nc]==nw-1)continue;
				if(y[nr][nc]==nw){
					if(vis[nr][nc]<=x+1)continue;
					vis[nr][nc] = x+1;
					pq.push({{nw+1,x+1},{nr,nc}});
					continue;
				}
	    		pq.push({{nw,x+1},{nr,nc}});
			}
		}
	}
    cout<<x<<endl;
    return 0;
}