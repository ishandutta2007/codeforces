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

vi to[MX];
vi ch[MX];
int w[MX];
bool used[MX];
int pdfs(int v){
	used[v] = true;
	int res = w[v];
	for (int u : to[v]) {
		if (used[u]) continue;
		res += pdfs(u);
		ch[v].pb(u);
	}
	return res;
}
vi ans;

void dfs(int v, int p=-1){
	ans.pb(v);
	w[v] ^= 1;
	for(int u : ch[v]) {
		dfs(u,v);
		ans.pb(v);
		w[v] ^= 1;
	}
	if (p != -1 && w[v]){
		ans.pb(p);
		w[p] ^= 1;
		ans.pb(v);
		w[v] ^= 1;
	}
}


int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	rep(i,m) {
		int a, b = 0;
		scanf("%d%d",&a,&b);
		a--;b--;
		to[a].pb(b);
		to[b].pb(a);
	}
	rep(i,n) scanf("%d",&w[i]);
	int sum = 0, root = 0;
	rep(i,n){ sum += w[i]; if (w[i]) root = i;}
	if (sum == 0) {
		puts("0");
		return 0;
	}

	if(pdfs(root) != sum) {
		puts("-1");
		return 0;
	}

	dfs(root);
	if (w[root]) ans.pop_back();

	printf("%d\n",sz(ans));
	rep(i,sz(ans)) printf("%d%c",ans[i]+1,i==sz(ans)-1?'\n':' ');
	
	return 0;
}