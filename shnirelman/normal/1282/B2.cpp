#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> s(n + 1, 0);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];

//    for(auto a1 : a)
//        cout << a1 << ' ';
//    cout << endl;

    int ans = 0;
    int p1 = p;
    for(int i = 0; i < k; i++) {
        int cnt = 0;
        for(int j = i + k - 1; j < n; j += k) {
            if(a[j] <= p) {
                p -= a[j];
                cnt += k;
            } else
                break;
        }

        int l = 0, r = i + 1;
        while(r - l > 1) {
            int m = (l + r) / 2;

            if(s[m] <= p)
                l = m;
            else
                r = m;
        }

        cnt += l;
        p -= s[l];

        if(l == i) {
            l = 0, r = min(k, n - cnt);
            while(r - l > 1) {
                int m = (l + r) / 2;

                if(s[cnt + m] - s[cnt] <= p)
                    l = m;
                else
                    r = m;
            }

            cnt += l;
        }

        ans = max(ans, cnt);
        p = p1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}