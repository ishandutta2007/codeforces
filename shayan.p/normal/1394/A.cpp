// And you curse yourself for things you never done
// Shayan.P  2020-08-12

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, d, m;
    cin >> n >> d >> m;
    vector<ll> v1, v2, sm2;
    ll sm = 0, ans = 0;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	if(x > m)
	    v1.PB(x);
	else
	    v2.PB(x), sm+= x;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sm2.PB(0);
    for(int x : v2){
	sm2.PB(sm2.back() + x);
    }
    ans = sm;
    for(int i = sz(v1)-1; i >= 0; i--){
	sm+= v1[i];
	ll need = 1ll * (sz(v1) - 1 - i) * d - i;
	need = max(need, ll(0));
	if(need > sz(v2))
	    continue;
	ans = max(ans, sm - sm2[need]);
    }
    return cout << ans << endl, 0;
}