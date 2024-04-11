#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool ip[200010];
vector<LL> sum[200010];
multiset<LL> st[200010];

int main() {
    for (int i = 2; i <= 200000; i++) ip[i] = is_prime(i);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> divisor;
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && ip[n / i]) {
                divisor.push_back(i);
            }
        }
        LL ans = 0;
        for (auto &d : divisor) {
            sum[d].assign(d, 0);
            for (int i = 0; i < n; i++) {
                sum[d][i % d] += a[i];
            }
            /*
            for (int i = 0; i < d; i++) {
                cout << d << ", " << i << " = " << sum[d][i] << '\n';
            }
            */
            st[d].clear();
            for (int i = 0; i < d; i++) {
                st[d].insert(sum[d][i]);
                ans = max(ans, sum[d][i] * d);
            }
        }
        cout << ans << '\n';
        while(q--) {
            int p, x;
            cin >> p >> x;
            --p;
            int delta = x - a[p];
            a[p] = x;
            LL ans = 0;
            for (auto &d : divisor) {
                LL old_sum = sum[d][p % d];
                LL new_sum = old_sum + delta;
                st[d].erase(st[d].find(old_sum));
                st[d].insert(new_sum);
                sum[d][p % d] = new_sum;
                ans = max(ans, *st[d].rbegin() * d);
            }
            cout << ans << '\n';
        }
    }
}