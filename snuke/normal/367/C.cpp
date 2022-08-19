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
#define adds(x,y) x = (x+(y))%mod;
#define muls(x,y) x = (x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int x[MX];

int f(int c){
	int a = c*(c-1)/2;
	if(c&1) return a+1;
	return a+c/2;
}

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	rep(i,m) scanf("%*d%d",&x[i]);
	sort(x,x+m);
	
	int l = 0, r = 10000, c;
	while(l+1<r){
		c = (l+r)/2;
		if(f(c) <= n) l = c; else r = c;
	}
	
	ll ans = 0;
	rrep(i,min(m,l)) ans += x[m-i];
	
	cout << ans << endl;
	
	return 0;
}