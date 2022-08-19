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

const int MX = 100005, MY = MX*2;
const int D = 1000, E = MX/D+5;

map<int,int> mp;
int pm[MY];
int mi(int i) {
	if (mp.find(i) == mp.end()) {
		pm[sz(mp)] = i;
		mp.insert(P(i,sz(mp)));
	}
	return mp[i];
}

int a[MX];
int f[E][MY];
// Binary Indexed Tree
typedef int TT;
struct bit{
	vector<TT> d; int sz;
	bit(){}
	bit(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		d.resize(sz+1); init(mx);
	}
	void init(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
	}
	void add(int i, TT x=1){ for(i=MX-2-i;i<=sz;i+=i&-i) d[i] += x;}
	TT sum(int i){
		TT x = 0; for(i=MX-2-i;i;i-=i&-i) x += d[i];
		return x;
	}
} d[E];
//

void up(int v, int p, int x) {
	for (int i = (p-1)/D+1; i < E; ++i) {
		d[i].add(f[i][v],-1);
		f[i][v] += x;
		d[i].add(f[i][v],1);
	}
}
int sol1(int p) {
	int v = a[p];
	int ap = (p-1)/D, bp = (p-1)%D+1, sp = D*ap;
	int res = f[ap][v];
	rrep(i,bp) res += (a[sp+i] == v);
	return res;
}
int cnt[MY];
int sol2(int p) {
	int ap = (p-1)/D, bp = (p-1)%D+1, sp = D*ap;
	int pi = sol1(p);
	int res = d[ap].sum(pi);
	rrep(i,bp) {
		int x = a[sp+i];
		cnt[x]++;
		res += (cnt[x]+f[ap][x] == pi);
	}
	rep(i,bp+1) cnt[a[sp+i]] = 0;
	return res;
}

int main(){
	rep(i,E) d[i] = bit(MX);
	int n, q;
	scanf("%d",&n);
	rrep(i,n) {
		scanf("%d",&a[i]);
		a[i] = mi(a[i]);
		up(a[i],i,1);
	}
	scanf("%d",&q);
	rep(qi,q) {
		int ty, x, y;
		scanf("%d%d%d",&ty,&x,&y);
		if (ty == 1) {
			up(a[y],y,-1);
			a[y] = mi(x);
			up(a[y],y,1);
		} else {
			int ans = 0;
			if (x == 1) ans = pm[a[y]];
			else if(x%2==0) ans = sol1(y);
			else ans = sol2(y);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}