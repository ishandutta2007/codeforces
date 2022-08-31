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
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

vector<int> to[MX];
char c[MX];
bool e[MX][26];

void dfs(int v, int p){
	int cnt[26]; rep(i,26) cnt[i] = 0;
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		dfs(u,v);
		rep(j,26){
			if(e[u][j]) cnt[j]++;
		}
	}
	//printf("%d :",v); rep(i,26) printf(" %d",cnt[i]); puts("");
	int mx = 0, mi = 0;
	rep(i,26){
		if(cnt[i] >= 2) mx = i+1;
		if(cnt[i]) e[v][i] = true;
	}
	rep(i,26){
		if(mx <= i && cnt[i] == 0){
			c[v] = 'Z'-i;
			mi = i;
			break;
		}
	}
	for(int i = mi-1; i >= 0; i--) e[v][i] = false;
	e[v][mi] = true;
}

int main(){
	int n, a, b;
	scanf("%d",&n);
	rep(i,n-1){
		scanf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	
	dfs(1,-1);
	
	rrep(i,n){
		printf("%c%c",c[i],i==n?'\n':' ');
	}
	
	return 0;
}