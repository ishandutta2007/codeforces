//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        a[i]--;

        if(a[i] < m)
            cnt[a[i]]++;
    }

    int ans = 0;
    vector<int> b(n);

    vector<int> c(n, 0);
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
        if(a[i] < m && c[a[i]] < n / m) {
            if(a[i] < m) {
                c[a[i]]++;
            }
        } else {
            for(int j = 0; j < m; j++) {
                if(cnt[j] < n / m) {
                    b[i] = j;
                    cnt[j]++;
                    c[j]++;
                    ans++;
                    break;
                }
            }
        }
    }

    cout << n / m << ' ' << ans << endl;
    for(auto x : b)
        cout << x + 1 << ' ';
    cout << endl;
}