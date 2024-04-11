#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 1e6 + 13;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int a[N];
int add[A];
int cnt[A];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int mx = 0, mn = A;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    if(k + 1 >= mn) {
        cout << mn << endl;
        return 0;
    }
//    cout << mx << endl;

    for(int i = 0; i < n; i++) {
        add[max(1, a[i] - k)]++;
        add[a[i] + 1]--;
    }
//cout << mx << endl;
    int cur = 0;
    for(int i = 0; i < A; i++) {
        cur += add[i];
        cnt[i] = cur;
    }
//cout << mx << endl;
    int ans = k + 1;
    for(int x = k + 2; x <= mx; x++) {
        int sum = 0;
        for(int i = x; i < A; i += x) {
            sum += cnt[i];
        }

        if(sum == n) {
            ans = x;
        }
    }

    cout << ans << endl;
}