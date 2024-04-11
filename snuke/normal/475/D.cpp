#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
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
typedef pair<int,ll> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[MX];

int gcd(int x, int y){return y?gcd(y,x%y):x;}
map<int,ll> mp;
vector<map<int,ll> > s;
int dfs(int l, int r) {
	if (l+1 == r) return a[l];
	int c = (l+r)>>1;
	int ld = dfs(l,c);
	int rd = dfs(c,r);
	int d = gcd(ld,rd);
	//printf("%d %d %d : %d %d %d\n", l, r, c, ld, rd, d);
	s[l][ld]++;
	if (r != c) {
		for (P p : s[c]) {
			//printf("l %d %I64d\n", p.fi,p.se);
			mp[p.fi] += p.se;
			s[l][gcd(ld,p.fi)] += p.se;
		}
	}
	s[r-1][rd]++;
	if (l != c-1) {
		for (P p : s[c-1]) {
			//printf("r %d %I64d\n", p.fi,p.se);
			mp[p.fi] += p.se;
			s[r-1][gcd(rd,p.fi)] += p.se;
		}
	}
	if (r != c && l != c-1) {
		for (P p : s[c]) {
			//printf("l %d %I64d\n", p.fi,p.se);
			for (P q : s[c-1]) {
				//printf("r %d %I64d\n", q.fi,q.se);
				mp[gcd(p.fi,q.fi)] += p.se*q.se;
			}
		}
	}
	return d;
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	s.resize(n);
	mp[dfs(0,n)]++;
	for (P p : s[0]) {
		//printf("L %d %I64d\n", p.fi,p.se);
		mp[p.fi] += p.se;
	}
	for (P p : s[n-1]) {
		//printf("R %d %I64d\n", p.fi,p.se);
		mp[p.fi] += p.se;
	}
	int q;
	scanf("%d",&q);
	rep(qi,q) {
		int x;
		scanf("%d",&x);
		ll ans = 0;
		auto it = mp.find(x);
		if (it != mp.end()) ans = it->se;
		printf("%I64d\n",ans);
	}
	
	return 0;
}