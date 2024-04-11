// Never let them see you bleed...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int maxn = 4e5 + 10, mod = 1e9 + 7;
const ll inf = 5e15;    

ll a[maxn];
int n;

ll solve(ll k){
    ll L, R;
    {
	ll l = 0, r = inf;
	while(r-l > 1){
	    ll mid = (l+r) >> 1;
	    ll cnt = 0;
	    for(int i = 0; i < n; i++)
		cnt+= (a[i] + mid-1) / mid;
	    if(cnt <= k)
		r = mid;
	    else
		l = mid;
	}
	R = r;
    }
    {
	ll l = 1, r = inf;
	while(r-l > 1){
	    ll mid = (l+r) >> 1;
	    ll cnt = 0;
	    for(int i = 0; i < n; i++)
		cnt+= a[i] / mid;
	    if(cnt >= k)
		l = mid;
	    else
		r = mid;
	}
	L = l;
    }
    for(int i = 0; i < n; i++){
	L = min(L, a[i]);
    }
    
    assert(L <= R);
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
	if(((a[i]+R-1) / R) > (a[i] / L)){
	    ll x = a[i] / L;
	    assert((a[i]+R-1) / R == x+1 && a[i] / R == x && a[i] / L == x && (a[i]+L-1) / L == x+1);
	    ll LL = min(L, a[i] / (x+1)), RR = max(R, (a[i] + x-1) / x);
	    mp[LL] = max(mp[LL], RR);
	}	    
    }
    if(mp.empty())
	return R-L;
    ll ans = inf, mx = R;
    if(L == 1){
	if(mp.count(0))
	    ans = mp[0]-1;
    }
    else{
	for(pll p : mp){
	    ans = min(ans, mx - p.F);
	    mx = max(mx, p.S);
	}
	ans = min(ans, mx - L);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	ll n, m, k;
	cin >> n >> m >> k;
	ll bef = 0;
	::n = 0;
	for(int i = 0; i < m; i++){
	    ll x;
	    cin >> x;
	    a[::n++] = x - bef;
	    bef = x;		
	}
	a[::n++] = n-bef;
	cout << solve(k + (::n)) << "\n";
    }
    return 0;
}