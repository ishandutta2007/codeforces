#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+10;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll n,q,x[MAX],y[MAX],z,a[MAX],b[MAX],res[MAX],ans,pb,id,r,u,v,aa,bb,pf[MAX];
set<int> s;
 
inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}
 
inline void f(int A,int B){
	pb = (pf[A] * pw(pf[B+1],MOD-2) % MOD);
	aa = a[A] - a[B+1]*pb % MOD;
	if(aa<0)aa+= MOD;
	aa = (1 - aa + MOD);
	if(aa>=MOD)aa-=MOD;
	bb = b[A] - b[B+1]*pb % MOD;
	if(bb<0)bb+= MOD;
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    s.insert(n+1), s.insert(1);
    rep(i,1,n)cin>>x[i], y[i] = 100-x[i];
    z = pw(100,MOD-2);
    pf[n+1] = 1;
    rap(i,n,1){
    	x[i] = x[i] * z % MOD, y[i] = y[i] * z % MOD;
    	pf[i] = pf[i+1] * x[i] % MOD;
    	b[i] = (b[i+1]*x[i] + 1)%MOD;
    	a[i] = (a[i+1]*x[i] + y[i])%MOD;
	}
	res[1] = ans = b[1] * pw((1 - a[1] + MOD)%MOD, MOD-2) % MOD;
	auto it = s.begin();
	while(q--){
		cin>>id;
		if(s.count(id)){
			it = s.find(id);
			--it, r = *it, ++it, u = *it, ++it, v = (*it) - 1;
			s.erase(id);
			f(r,u-1);
			ans-= bb * pw(aa, MOD-2) % MOD;
			f(u,v);
			ans-= bb * pw(aa, MOD-2) % MOD;
			f(r,v);
			ans+= bb * pw(aa, MOD-2) % MOD;
		}
		else {
			s.insert(id);
			it = s.find(id);
			--it, r = *it, ++it, u = *it, ++it, v = (*it) - 1;
			f(r,u-1);
			ans+= bb * pw(aa, MOD-2) % MOD;
			f(u,v);
			ans+= bb * pw(aa, MOD-2) % MOD;
			f(r,v);
			ans-= bb * pw(aa, MOD-2) % MOD;
		}
		while(ans<0)ans+= MOD;
		while(ans>=MOD)ans-= MOD;
		cout<<ans<<endl;
	}
    return 0;
}