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
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 1005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x;
int a[MX], l[MX];
bool dp[MX];

int dfs(int v){
	if(a[v] == 0) return v;
	if(a[v] < 0) return -a[v];
	if(a[v] == x) return v;
	int t = dfs(a[v]);
	a[v] = -t;
	l[t]++;
	return t;
}

int main(){
	int n, mx = 1, t;
	scanf("%d%d",&n,&x);
	rrep(i,n) scanf("%d",&a[i]);
	rrep(i,n) dfs(i);
	
	dp[0] = true;
	rrep(i,n){
		if(a[i] != 0 || i == -a[x] || i == x) continue;
		t = l[i]+1;
		drep(j,mx){
			if(dp[j]) dp[j+t] = true;
		}
		mx += t;
	}
	t = 1;
	if(a[x] != 0) t = l[-a[x]]+1;
	
	rep(i,mx){
		if(dp[i]) printf("%d\n",i+t);
	}
	
	return 0;
}