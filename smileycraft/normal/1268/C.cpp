
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

// Prefix sum tree. Use one-based indices.
template <typename T = ll>
struct fenwick_tree{
	vector<T> t;

	fenwick_tree(ll n) : t(n + 1) {}

	// Calculate prefix sum up and till the i'th entry in O(log(n)) time.
	T query(ll i){
		T s = 0;
		for(; i > 0; i -= (i & (-i))) s += t[i];
		return s;
	}
	T query(ll l, ll r) {return query(r) - query(l - 1);}

	// Increment the i'th entry by v in O(log(n)) time.
	void increment(ll i, T v){
		for(; i < t.size(); i += (i & (-i))) t[i] += v;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n;
    cin >> n;
    vll v(n), loc(n);
    for (ll i = 0; i < n; ++i){
        cin >> v[i];
        --v[i];
        loc[v[i]] = i;
    }
    fenwick_tree<> amount(n);
    set<ll> done;
    ll center = 0, total = 0;
    for (ll i = 0; i < n; ++i){
        total += max<ll>(i - 2 * amount.query(loc[i] + 1), 0);
        amount.increment(loc[i] + 1, 1);
        done.insert(loc[i]);
        ll left = amount.query(center), right = i + 1 - amount.query(center + 1);
        if (i == 0) center = loc[i];
        else if (left + 1 < right) center = *(done.upper_bound(center));
        else if (left > right + 1) center = *(--(done.lower_bound(center)));
        if (loc[i] < center) total += (center - loc[i]) - (amount.query(center + 1) - amount.query(loc[i] + 1));
        else if (loc[i] > center) total += (loc[i] - center) - (amount.query(loc[i] + 1) - amount.query(center + 1));
        cout << total << endl;
    }
    return 0;
}