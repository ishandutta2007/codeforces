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
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int p[MX];

map<int,int> mp;
int e[MX][2];
int ans[MX];
bool used[MX];

int dfs(int v){
	if (used[v]) return -1;
	used[v] = true;
	rep(i,2) {
		if (e[v][i] == -1) continue;
		int r = dfs(e[v][i]);
		if (r == -1) continue;
		ans[v] = ans[r] = i;
		return -1;
	}
	return v;
}

int main(){
	int n, a, b;
	scanf("%d%d%d",&n,&a,&b);
	rep(i,n) scanf("%d",&p[i]);
	rep(i,n) mp.insert(P(p[i],i));
	rep(i,n) {
		if (mp.find(a-p[i]) == mp.end()) e[i][0] = -1;
		else {
			e[i][0] = mp[a-p[i]];
			if (e[i][0] == i) e[i][0] = -1;
		}
		if (mp.find(b-p[i]) == mp.end()) e[i][1] = -1;
		else {
			e[i][1] = mp[b-p[i]];
			if (e[i][1] == i) e[i][1] = -1;
		}
	}
	//rep(i,n) printf("%d %d\n",e[i][0],e[i][1]);
	rep(ti,4) {
		bool ok = true;
		rep(i,n) ans[i] = -1;
		rep(i,n) used[i] = false;
		if (ti&1) {
			if (a%2==0 && mp.find(a/2) != mp.end()) {
				ans[mp[a/2]] = 0;
				used[mp[a/2]] = true;
			}
		}
		if (ti&2) {
			if (b%2==0 && mp.find(b/2) != mp.end()) {
				ans[mp[b/2]] = 1;
				used[mp[b/2]] = true;
			}
		}
		rep(i,n) {
			if (used[i]) continue;
			if (dfs(i) != -1) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		puts("YES");
		rep(i,n) printf("%d%c",ans[i],i==n-1?'\n':' ');
		return 0;
	}
	puts("NO");
	
	return 0;
}