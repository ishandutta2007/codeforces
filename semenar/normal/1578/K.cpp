#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tests;
    cin >> tests;

    int N = 200 * 100 + 1;
    vector<bool> is_prime(N, true);
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }


    for (int test = 0; test < tests; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int tot_sum = 0;
        for (int i = 0; i < n; i++) tot_sum += a[i];
        if (!is_prime[tot_sum]) {
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << i + 1 << ' ';
            cout << endl;
        }
        else {
            for (int j = 0; j < n; j++) {
                if (!is_prime[tot_sum - a[j]]) {
                    cout << n - 1 << endl;
                    for (int i = 0; i < n; i++) if (i != j) cout << i + 1 << ' ';
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}