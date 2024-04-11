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
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

ll f(ll x){
	if(x == 0) return 1;
	ll a = f(x/2);
	a = (a*a)%mod;
	if(x&1) return a*2%mod;
	return a;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	ll a = n-m, ans, x;
	if(a*k >= n-(k-1)){
		cout << m << endl;
	} else {
		ans = a*(k-1); x = 0;
		n -= a*k;
		ans += n%k;
		n -= n%k;
		ans = (ans+(((f(n/k)-1+mod)%mod)*2*k%mod))%mod;
		cout << ans << endl;
	}
	
	return 0;
}