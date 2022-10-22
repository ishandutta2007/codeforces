#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pw2[N];
int a[N];

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(31, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int c = 0;
        while(x % 2 == 0) {
            c++;
            x /= 2;
        }

        cnt[c]++;
    }

    int ans = dif(pw2[n], pw2[n - cnt[0]]);

    int cur = n - cnt[0];
    for(int i = 1; i < cnt.size(); i++) {
//        cout << i << ' ' << cnt[i] << ' ' << ans << endl;
        if(cnt[i] > 0)
            ans = sum(ans, mul(pw2[cur - cnt[i]], dif(pw2[cnt[i] - 1], 1)));

        cur -= cnt[i];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) {
        pw2[i] = mul(pw2[i - 1], 2);
    }

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}