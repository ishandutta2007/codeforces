#include<bits/stdc++.h>
using namespace std;

set<int> small, big;
map<int, int> type;
long long sum;
int cnt, cnt_big;
long long all_sum;

void relax() {
    while (big.size() < cnt) {
        int x = *small.rbegin();
        big.insert(x);
        cnt_big += type[x];
        sum += x;
        small.erase(x);
    }
    while (big.size() > cnt) {
        int x = *big.begin();
        big.erase(x);
        cnt_big -= type[x];
        sum -= x;
        small.insert(x);
    }
    while (!small.empty() && !big.empty() && *small.rbegin() > *big.begin()) {
        int x1 = *small.rbegin(), x2 = *big.begin();
        small.erase(x1);
        big.erase(x2);
        sum -= x2;
        cnt_big -= type[x2];
        small.insert(x2);
        big.insert(x1);
        sum += x1;
        cnt_big += type[x1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int t, d;
        cin >> t >> d;
        if (d < 0) {
            d = -d;
            all_sum -= d;
            cnt -= t;
            if (small.count(d)) small.erase(d); else {
                cnt_big -= t;
                sum -= d;
                big.erase(d);
            }
        } else {
            type[d] = t;
            cnt += t;
            small.insert(d);
            all_sum += d;
        }
        relax();
        long long ans = all_sum + sum;
        if (cnt_big == cnt && cnt != 0) {
            ans -= *big.begin();
            if (!small.empty()) ans += *small.rbegin();
        }
        cout << ans << '\n';
    }
    return 0;
}