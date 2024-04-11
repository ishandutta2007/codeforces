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

const int MX = 1000005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

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
map<ll,int> mp;
int f(ll x){
	map<ll,int>::iterator it = mp.find(x);
	if(it != mp.end()) return (*it).se;
	ll x1 = x;
	int res = 0;
	rep(i,ps.size()){
		int p = ps[i];
		while(x%p==0){ res++; x /= p;}
	}
	mp[x1] = res+(x==1?0:1);
	return res+(x==1?0:1);
}

int n;
ll a[8], b[8];
bool u[8];
int ans;
bool z[1<<8];

void dfs(int x){
	if(x < 0){
		int c = n, cnt = 0, res;
		rep(i,n){
			res = f(b[i]);
			if(res == 1 && a[i]==b[i]) res--;
			c += res;
			if(!u[i]) cnt++;
		}
		if(cnt >= 2) c++;
		ans = min(ans,c);
		return;
	}
	drep(i,(1<<x)){
		int m = i; ll y = a[x];
		bool ok = true;
		rep(j,x){
			if(m&1){
				if(u[j] || y%b[j]!=0) ok = false; else y/=b[j];
			}
			m >>= 1;
		}
		if(!ok) continue;
		m = i;
		rep(j,x){
			if(m&1){
				b[x] /= b[j];
				u[j] = true;
			}
			m >>= 1;
		}
		dfs(x-1);
		m = i;
		rep(j,x){
			if(m&1){
				u[j] = false;
			}
			m >>= 1;
		}
		b[x] = a[x];
	}
}

int main(){
	cin >> n;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	
	sieve(MX);
	ans = INF;
	rep(i,n) b[i] = a[i];
	
	dfs(n-1);
	
	cout << ans << endl;
	
	return 0;
}