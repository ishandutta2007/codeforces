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

const int MX = 1000005, INF = 1000010000;
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

int main(){
	sieve(MX);
	int x = 0;
	cin >> x;
	rep(i,x) {
		if (i < 2 || x-i < 2) continue;
		if (!pf[i] && !pf[x-i]) {
			printf("%d %d\n",i,x-i);
			return 0;
		}
	}
	
	return 0;
}