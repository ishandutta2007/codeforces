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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

char c[MX];

vector<vi> d(1,vi(26,-1));

int dfs(int v) {
	int x = 0;
	int s = 0;
	rep(i,26) {
		if (d[v][i] == -1) continue;
		++s;
		int r = dfs(d[v][i]);
		x |= r^3;
	}
	if (!s) return 1;
	return x;
}

int main(){
	int n, k;
	string s;
	scanf("%d%d",&n,&k);
	rep(i,n) {
		scanf("%s",c);
		s = c;
		int v = 0;
		rep(i,sz(s)) {
			int x = s[i]-'a';
			if (d[v][x] == -1) {
				d[v][x] = sz(d);
				d.pb(vi(26,-1));
			}
			v = d[v][x];
		}
	}
	int f = dfs(0);
	string a1 = "First", a2 = "Second";
	if (f == 3) cout << a1 << endl;
	else if(f == 0) cout << a2 << endl;
	else if (f == 1) cout << a2 << endl;
	else cout << (k%2?a1:a2) << endl;
	
	return 0;
}