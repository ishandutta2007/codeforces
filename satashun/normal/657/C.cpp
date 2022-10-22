#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, k, b, c;
ll ret = LLONG_MAX;
ll t[200010];

ll gc(ll x, ll lv)
{
    ll df = lv - x;
    return df / 5 * b + df % 5 * c;
}

int main() {
    cin >> n >> k >> b >> c;
    b = min(b, c * 5);

    rep(i, n) cin >> t[i];
    sort(t, t + n);

    rep(md, 5) {
	ll lv = t[k-1];
	while ((lv % 5 + 5) % 5 != md) ++lv;

	multiset<ll> st;
	
	ll sum = 0;
	rep(i, k) {
	    st.insert(gc(t[i], lv));
	    sum += gc(t[i], lv);
	}
	ret = min(ret, sum);

	ll fr = lv;
	ll cu = 0;

	for (int i = k; i < n; ++i) {    
	    if (lv < t[i]) {
		lv += (t[i] - lv + 4) / 5 * 5;
	    }

	    ll up = (lv - fr) / 5 * b;
	    ll nc = gc(t[i], lv) - up;

	    if (*st.rbegin() < nc) continue;
	    sum -= *st.rbegin();
	    auto it = st.end();
	    --it;
	    st.erase(it);
	    
	    sum += nc;
	    st.insert(nc);
	    ret = min(ret, sum + up * k);   
	}
    }

    cout << ret << endl;
    return 0;
}