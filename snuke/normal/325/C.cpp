#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 314000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, m;
int a[MX], c[MX], d[MX], e[MX];
vector<int> t[MX], u[MX], b[MX];
bool can[MX], ok[MX], used[MX];
int mn[MX], mx[MX];

int main(){
	int x, y, z;
	scanf("%d%d",&m,&n);
	
	rep(i,m){
		scanf("%d%d",&x,&y);
		t[--x].pb(i);
		rep(j,y){
			scanf("%d",&z);
			if(z == -1) c[i]++; else{
				b[i].pb(--z);
				u[z].pb(i);
			}
		}
		d[i] = b[i].size();
		e[i] = x;
	}
	
	/*
	rep(i,m) printf("%d ",d[i]); puts("");
	rep(i,n){
		printf("%d : ",i);
		rep(j,t[i].size()) printf("%d ",t[i][j]); puts("");
	}//*/
	
	queue<int> q;
	rep(i,n){
		bool bl = false;
		rep(j,t[i].size()) if(!d[t[i][j]]) bl = true;
		if(bl) q.push(i);
	}
	
	while(!q.empty()){
		x = q.front(); q.pop();
		if(can[x]) continue;
		can[x] = true;
		rep(i,u[x].size()){
			d[u[x][i]]--;
			if(!d[u[x][i]]) q.push(e[u[x][i]]);
		}
	}
	
	rep(i,m){
		x = e[i];
		d[i] = b[i].size();
		if(!can[x]) continue;
		bool bl = true;
		rep(j,b[i].size()){
			if(!can[b[i][j]]) bl = false;
		}
		if(bl) ok[i] = true;
	}
	
	rep(i,n){
		if(!can[i]) continue;
		bool bl = true;
		mn[i] = mod; mx[i] = 0; a[i] = 0;
		rep(j,t[i].size()){
			x = t[i][j];
			if(ok[x] && b[x].size()){
				bl = false;
				a[i]++;
			}
		}
		if(bl) q.push(i);
	}
	
	
	while(!q.empty()){
		x = q.front(); q.pop();
		if(used[x]) continue;
		used[x] = true;
		if(!can[x]) continue;
		int dw = mod, up = 0;
		int dwx, upx;
		rep(i,t[x].size()){
			y = t[x][i];
			if(!ok[y]) continue;
			dwx = upx = c[y];
			rep(j,b[y].size()){
				dwx += mn[b[y][j]];
				upx += mx[b[y][j]];
				dwx = min(dwx,mod);
				upx = min(upx,mod);
			}
			
			dw = min(dw,dwx);
			up = max(up,upx);
		}
		mn[x] = dw; mx[x] = min(mod,up);
		
		rep(i,u[x].size()){
			if(!ok[u[x][i]]) continue;
			d[u[x][i]]--;
			if(!d[u[x][i]]){
				y = e[u[x][i]];
				a[y]--;
				if(!a[y]) q.push(y);
			}
		}
	}
	
	priority_queue<P,vector<P>,greater<P> > pq;
	rep(i,n){
		if(!can[i] || used[i]) continue;
		mx[i] = -2;
		rep(j,t[i].size()){
			x = t[i][j];
			if(ok[x] && !d[x]){
				z = c[x];
				rep(k,b[x].size()){
					z += mn[b[x][k]];
					z = min(z,mod);
				}
				mn[i] = min(mn[i],z);
			}
		}
		pq.push(P(mn[i],i));
	}
	
	while(!pq.empty()){
		x = pq.top().se; pq.pop();
		if(used[x]) continue;
		used[x] = true;
		if(!can[x]) continue;
		
		rep(i,u[x].size()){
			z = u[x][i];
			if(!ok[z]) continue;
			d[z]--;
			if(!d[z]){
				y = e[z];
				int cnt = c[z];
				rep(j,b[z].size()){
					cnt += mn[b[z][j]];
					cnt = min(cnt,mod);
				}
				if(cnt < mn[y]){
					mn[y] = cnt;
					pq.push(P(cnt,y));
				}
			}
		}
	}
	
	rep(i,n){
		if(can[i]){
			printf("%d %d\n",mn[i],mx[i]);
		} else {
			printf("-1 -1\n");
		}
	}
	
	return 0;
}