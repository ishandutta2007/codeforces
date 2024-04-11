#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<ii> weary;
    int n;
    ll S;
    cin >> n >> S;
    ll sum_s = 0, cur = 0, ans, good = 0;
    for(int i = 0; i < n; i++) {
        ll s, a, b;
        cin >> s >> a >> b;
        sum_s += s;
        cur += a * s;
        weary.push({b - a, s});
        if(b - a > 0)
            good += s;
    }
    ans = cur;
    ll sl = (sum_s + S - 1) / S;
    sl *= S;
    ll ex = sl - sum_s;
    //cout << good << endl;
    //cout << ans << endl;
    while(good >= S) {
        //cout << good << endl;
        auto p = weary.top(); weary.pop();
        ll cnt = p[1], profit = p[0];
        if(cnt >= S) {
            cur += profit * (S * (cnt / S));
            good -= S * (cnt / S);
            cnt %= S;
            ans = max(ans, cur);
            if(cnt)
                weary.push({profit, cnt});
            continue;
        }
        cur += profit * cnt;
        good -= cnt;
        ll rem = S - cnt;
        //cout << "rem = " << rem << endl;
        while(rem) {
            auto q = weary.top(); weary.pop();
            ll take = min(q[1], rem);
            //cout << take << endl;
            rem -= take;
            good -= take;
            cur += q[0] * take;
            q[1] -= take;
            if(q[1])
                weary.push(q);
        }
    }
    //cout << good << endl;
    ans = max(ans, cur);
    //cout << ans << endl;
    ll rem = S;
    while(rem && weary.size()) {
        //cout << rem << " ";
        //cout << endl;
        if(weary.top()[0] >= 0) {
            auto p = weary.top(); weary.pop();
            ll take = min(rem, p[1]);
            p[1] -= take;
            rem -= take;
            cur += p[0] * take;
            continue;
        }
        if(rem <= ex) {
            rem = 0;
            continue;
        }
        rem -= ex;
        while(rem) {
            auto p = weary.top(); weary.pop();
            ll take = min(rem, p[1]);
            p[1] -= take;
            rem -= take;
            cur += p[0] * take;
        }
        break;
    }
    ans = max(ans, cur);
    cout << ans << '\n';
}