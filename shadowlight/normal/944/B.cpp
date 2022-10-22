#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n;
    cin >> n;
    map <ll, ll> cnt;
    ll mink = INF, maxk = -INF;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        mink = min(mink, x);
        maxk = max(maxk, x);
        cnt[x]++;
    }
    ll res = INF, cnt1 = -1, cnt2 = -1;
    ll sum1 = n * (mink + 1);
    for (ll i = 0; i <= n; i++) {
        ll sum2 = sum1 - i;
        ll now3 = sum - sum2;
        ll now2 = n - i - now3;
        if (now2 && mink + 1 > maxk) continue;
        if (now3 && mink + 2 > maxk) continue;
        if (now2 < 0 || now3 < 0) continue;
        if (res > min(i, cnt[mink]) + min(now2, cnt[mink + 1]) + min(now3, cnt[mink + 2])) {
            res = min(i, cnt[mink]) + min(now2, cnt[mink + 1]) + min(now3, cnt[mink + 2]);
            cnt1 = i, cnt2 = now2;
        }
    }
//    for (ll i = 0; i <= n; i++) {
//        ll sum1 = i * (mink + 1);
//        if (i && mink + 1 > maxk) continue;
//        sum1 += x * (mink + 1);
//        ll now1 = n - i - (sum - sum1);
//        if (now2 < 0) continue;
//        ll now3 = sum - sum1;
//        if (now3 < 0) continue;
//        if (res > min(now1, cnt[mink]) + min(i, cnt[mink + 1]) + min(now2, cnt[mink + 2])) {
//            res = min(now1, cnt[mink]) + min(i, cnt[mink + 1]) + min(now2, cnt[mink + 2]);
//            cnt2 = i, cnt1 = now1;
//        }
//    }
    cout << res << "\n";
    for (ll i = 0; i < cnt1; i++) {
        cout << mink << " ";
    }
    for (ll i = 0; i < cnt2; i++) {
        cout << mink + 1 << " ";
    }
    for (ll i = 0; i < n - cnt1 - cnt2; i++) {
        cout << mink + 2 << " ";
    }
}