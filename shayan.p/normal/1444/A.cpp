#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

ll f(ll a, ll b, ll p){
    while(a % b == 0)
	a/= p;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	ll a, b;
	cin >> a >> b;
	if(a % b != 0){
	    cout << a << "\n";
	    continue;
	}
	ll ans = 1;
	ll x = b;
	for(int i = 2; i * i <= x; i++){
	    if(x % i == 0){
		while(x % i == 0)
		    x/= i;
		ans = max(ans, f(a, b, i));
	    }
	}
	if(x > 1){
	    ans = max(ans, f(a, b, x));
	}
	cout << ans << "\n";
    }
}