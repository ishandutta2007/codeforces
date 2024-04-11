// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int a[70];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	ll t;
        int n;
	cin >> t >> n;
	memset(a, 0, sizeof a);
	ll total = 0;
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    a[ __builtin_ctz(x) ]++;
	    total+= x;
	}
	if(total < t){
	    cout << -1 << "\n";
	}
	else{
	    int mn = 100, ans = 0;
	    for(int i = 0; i < 62; i++){
		if(a[i] && mn != 100){
		    ans+= i - mn;
		    mn = 100;
		    --a[i];
		}		
		if(bit(t, i) && a[i] == 0){
		    mn = min(mn, i);
		}
		if(bit(t, i) && a[i] != 0){
		    a[i]--;
		}
		a[i+1]+= a[i]/2;
	    }
	    cout << ans << "\n";
	}
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")