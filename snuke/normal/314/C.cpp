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

const int MX = 100005, MY = 1000005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

// Binary Indexed Tree
struct bit{
	vector<ll> d; int sz;
	bit(){}
	bit(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		d.resize(sz+1); init(mx);
	}
	void init(int mx, bool fil=false){
		sz = 1; while(sz < mx) sz <<= 1;
		if(fil){ rrep(i,sz) d[i] = i&-i;} else { rrep(i,sz) d[i] = 0;}
	}
	void add(int i, ll x=1){ for(;i<=sz;i+=i&-i) d[i] = (d[i]+x)%mod;}
	ll sum(int i){
		if(i == 0) return 1;
		ll x = 1; for(;i;i-=i&-i) x = (x+d[i])%mod;
		return x;
	}
};
//
bit dp(MY);

int main(){
	int n, a; ll x, y;
	scanf("%d",&n);
	
	rep(i,n){
		scanf("%d",&a);
		x = dp.sum(a); y = x-dp.sum(a-1);
		dp.add(a,(x*a-y+mod)%mod);
	}
	
	cout << dp.sum(MY)-1 << endl;
	
	return 0;
}