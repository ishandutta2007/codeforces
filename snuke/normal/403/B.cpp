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

const int MX = 5005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Eratosthenes' sieve
vector<int> ps; vector<bool> pf;
void sieve(int mx){
	pf.resize(mx+1); fill(rng(pf),true); pf[0] = pf[1] = false;
	for(ll i = 2; i <= mx; i++){
		if(!pf[i]) continue;
		ps.pb(i);
		for(ll j = i*i; j <= mx; j+=i) pf[j] = false;
	}
}
//

int gcd(int x, int y){ return y?gcd(y,x%y):x;}
int n, m;
int a[MX], b[MX], g[MX];

int f(int x){
	int s = 0;
	rep(i,ps.size()){
		int c = 0;
		while(x%ps[i]==0) x /= ps[i], ++c;
		if(c && binary_search(b,b+m,ps[i])) s -= c;
		else s += c;
	}
	if(x != 1){
		if(binary_search(b,b+m,x)) --s;
		else ++s;
	}
	return s;
}

int main(){
	sieve(100005);
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);
	sort(b,b+m);
	
	int x = a[0];
	int ans = 0;
	rep(i,n){
		x = gcd(x,a[i]);
		g[i] = x;
		ans += f(a[i]);
	}
	
	x = 1;
	for(int i = n-1; i >= 0; --i){
		int y = g[i]/x;
		int z = f(y);
		if(z < 0){
			ans -= z*(i+1);
			x *= y;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}