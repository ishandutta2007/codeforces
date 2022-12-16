// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 5010, mod = 998244353;

void mv(ll &a, ll &b, vector<pll> &v){// b markaz e
    if(a == b)
	return;
    v.PB({a, b});
    a = 2 * b - a;
}
void mv(ll &a, ll &b, vector<pll> &v, map<ll, int> &mp){
    if(a == b)
	return;
    ll c = 2 * b - a;
    while(mp[a]--)
	mp[c]++, v.PB({a, b});
    mp.erase(a);
    
}
void mv2(ll &a, ll &b, ll &c, vector<pll> &v){
    mv(c, a, v);
    mv(c, b, v);
}
void solve(ll *a, vector<pll> &v){
    sort(a, a+4);
    while(a[3] - a[0] > 1){
	ll ln = (a[3] - a[0] + 3) /4;
	ll L = a[0] + ln, R = a[3] - ln, md = (a[0] + a[3]) /2;
	while( (a[1]<L || R<a[1]) && (a[2]<L || R<a[2]) ){
	    if(L < a[1])
		mv2(a[3], a[1], a[2], v);
	    else if(a[2] < L)
		mv2(a[0], a[2], a[1], v);
	    else if(a[1] - a[0] < a[3] - a[2])
		mv2(a[2], a[3], a[1], v);
	    else
		mv2(a[1], a[0], a[2], v);	    
	    sort(a, a+4);
	}
	if(L<=a[1] && a[1]<=R){
	    if(a[1] <= md)
		mv(a[0], a[1], v);
	    else
		mv(a[2], a[1], v), mv(a[3], a[1], v);
	}
	else{
	    if(a[2] <= md)		
		mv(a[0], a[2], v), mv(a[1], a[2], v);
	    else
		mv(a[3], a[2], v);
	}
	sort(a, a+4);
    }
    if(a[0] != a[1]){
	mv(a[1], a[0], v);
    }
    else if(a[1] != a[2]){
	mv(a[1], a[2], v);
    }
    else{
	mv(a[2], a[3], v);
    }
    
    map<ll, int> mp;
    for(int i = 0; i < 4; i++)
	mp[ a[i] ]++;
    while( (mp.rbegin()->F) - (mp.begin()->F) > 1 ){
	ll A = mp.begin() ->F, B = (++mp.begin())->F, C = mp.rbegin()->F;
	if(A<=0 && 0<B)
	    mv(C, B, v, mp);
	else if(B<=0 && 0<C)
	    mv(A, B, v, mp);
	else if(0<A)
	    mv(C, A, v, mp);
	else if(C<=0)
	    mv(A, C, v, mp);
    }    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    ll a[4], b[4];
    
    for(int i = 0; i < 4; i++)
	cin >> a[i];
    for(int i = 0; i < 4; i++)
	cin >> b[i];
    ll g1 = 0, g2 = 0;
    for(int i = 0; i < 3; i++)
	g1 = __gcd(g1, abs( a[i] - a[i+1] ));
    for(int i = 0; i < 3; i++)
	g2 = __gcd(g2, abs( b[i] - b[i+1] ));
    if(g1 != g2)
	return cout << -1 << endl, 0;
    if(g1 == 0){
	if(a[0] == b[0])
	    return cout << 0 << endl, 0;
	else
	    return cout << -1 << endl, 0;
    }
    ll g = g1;    
    ll k = ( (a[0] % g) + g ) %g;
    if( k != ( (b[0] % g) + g ) %g )
	return cout << -1 << endl, 0;
    for(int i = 0; i < 4; i++)
	a[i]-=k, a[i]/=g, b[i]-=k, b[i]/=g;
    int num = 0;
    for(int i = 0; i < 4; i++)
	num+= a[i] & 1, num-= b[i] & 1;
    if(num != 0)
	return cout << -1 << endl, 0;
    vector<pll> ans;
    solve(a, ans);
    int SZ = sz(ans);
    solve(b, ans);
    reverse(ans.begin() + SZ, ans.end());    
    for(int i = SZ; i < sz(ans); i++)
	ans[i].F = 2 * ans[i].S - ans[i].F;
    cout << sz(ans) <<"\n";
    for(pll p : ans)
	cout << p.F * g + k << " " << p.S * g + k << "\n";
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")