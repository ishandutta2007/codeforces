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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define sz(x) (int)(x).size()
#define popcount __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 2005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int a[MX][MX];
bool used[MX];
int n;

int cnt;
void dfs(int v){
	if(used[v]) return;
	used[v] = true;
	rep(i,n){
		if(a[v][i]) dfs(i);
	}
}

void rdfs(int v){
	if(!used[v]) return;
	used[v] = false;
	cnt++;
	rep(i,n){
		if(a[i][v]) rdfs(i);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n)rep(j,n) scanf("%d",&a[i][j]);
	string ans = "YES";
	dfs(0);
	rdfs(0);
	if(cnt != n) ans = "NO";
	
	cout << ans << endl;
	
	return 0;
}