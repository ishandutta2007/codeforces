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
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned u;

const int MX = 50005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v
const int mod = 9998141;
const int K = 450;

map<u,int> m;
int mi;
int p[MX][4];
char in[MX];

int main(){
	string s;
	scanf("%s",in);
	s = in;
	int n = sz(s);
	vvi d;
	rep(j,n){
		u x = 0;
		rrep(i,4){
			p[j][i-1] = INF;
			if(j+i > n) continue;
			x = x*mod+s[j+i-1];
			if(m.count(x) == 0){ m[x] = mi++; d.pb(vi(0));}
			p[j][i-1] = m[x];
			d[p[j][i-1]].pb(j);
		}
	}
	vi tmp = vi(mi,INF);
	vvi fr(mi), ba(mi);
	rep(i,mi){
		if(sz(d[i]) < K) continue;
		fr[i] = tmp;
		ba[i] = tmp;
		int pre = -INF;
		rep(j,n){
			rep(k,4){
				if(p[j][k] == INF) continue;
				if(p[j][k] == i) pre = j;
				fr[i][p[j][k]] = min(fr[i][p[j][k]], j-pre);
			}
		}
		pre = INF+n;
		drep(j,n){
			rep(k,4){
				if(p[j][k] == INF) continue;
				if(p[j][k] == i) pre = j;
				ba[i][p[j][k]] = min(ba[i][p[j][k]], pre-j);
			}
		}
	}
	int q;
	scanf("%d",&q);
	rep(qi,q){
		scanf("%s",in);
		string t = in;
		scanf("%s",in);
		string o = in;
		u tx = 0, ox = 0;
		rep(i,sz(t)) tx = tx*mod+t[i];
		rep(i,sz(o)) ox = ox*mod+o[i];
		if(m.count(tx) == 0 || m.count(ox) == 0){
			puts("-1");
			continue;
		}
		int ti = m[tx], oi = m[ox];
		if(sz(d[ti]) < sz(d[oi])){
			swap(t,o);
			swap(tx,ox);
			swap(ti,oi);
		}
		int ans = INF;
		if(sz(d[ti]) >= K){
			if(fr[ti][oi] < INF){
			 	ans = min(ans,fr[ti][oi]+sz(o));
			}
			if(ba[ti][oi] < INF){
			 	ans = min(ans,ba[ti][oi]+sz(t));
			}
		} else {
			int i = 0, j = 0;
			while(i < sz(d[ti]) && j < sz(d[oi])){
				if(d[ti][i] < d[oi][j]){
					ans = min(ans,d[oi][j]-d[ti][i]+sz(o));
					++i;
				} else {
					ans = min(ans,d[ti][i]-d[oi][j]+sz(t));
					++j;
				}
			}
		}
		ans = max(ans,max(sz(t),sz(o)));
		printf("%d\n",ans);
	}
	
	return 0;
}