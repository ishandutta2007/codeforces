#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll
start_diff(ll k)
{
    return 1ll * k * (k - 1) / 2;
}

ll
get_inner_diff(pii bucket, ll pos, ll k)
{
    ll cnt, add;
    tie(cnt, add) = bucket;
    if (pos <= cnt) {
        return -pos;
    } else if (pos == cnt + 1) {
        return add - pos;
    } else {
        return k - pos;
    }
}

pair<ll, ll>
gen_bucket(ll bid, ll k)
{
    ll diff = start_diff(k);
    if (bid > 0) {
        auto bpar = gen_bucket(bid / k, k);
        diff += get_inner_diff(bpar, bid % k, k);
    }
    ll cnt = (diff - 1) / k;
    diff -= 1ll * cnt * k;
    return make_pair(cnt, k - (diff - 1));
}

ll
solve(ll n, ll k)
{
    if (n <= k) return n;
    ll blen = (1ll * k * k + 1) * k;
    ll bid = (n - k - 1) / blen, bpos = (n - k - 1) % blen;
    ll cnt, add;
    auto bucket = gen_bucket(bid, k);
    tie(cnt, add) = bucket;
    ll len = 1ll * k * k + 1;
    ll pos = bpos / len, spos = bpos % len;
    // find special number in current interval
    ll bad_pos = start_diff(k) - 1 + get_inner_diff(bucket, pos, k);
    if (spos == bad_pos) {
        // n is a special number (i.e. sum of k numbers)
        // so find first number in sequence generating it
        ll gen_n = (n - 1ll * k * (k - 1) / 2) / k;
        return solve(gen_n, k) + k;
    } else {
        // 0. now ans considers all numbers before n (including n)
        ll ans = n;
        // 1. remove all numbers up to n that are sums of k numbers
        ans -= bid * k + pos;
        if (spos > bad_pos) {
            ans--;
        }
        // 2. add sums for all generating sequences lying before n
        ans += 1 + bid * k * k + 1ll * k * pos;
        if (spos > bad_pos) {
            ans += (spos - 1) / k;
        } else {
            ans += spos / k;
        }
        return ans;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}