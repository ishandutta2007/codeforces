#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

const int N = 1e6 + 7;

int t[N];

void upd(int i, int x) {
    for (; i < N; i += i & -i) t[i] += x;
}

int get(int r) {
    int s = 0;
    for (; r > 0; r -= r & -r) s += t[r];
    return s;
}

int kth(int k) {
    int l = 0, r = N - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(m) >= k) r = m; else l = m;
    }
    return r;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        upd(a, 1);
    }
    while (q--) {
        int k;
        cin >> k;
        if (k > 0) upd(k, 1); else upd(kth(-k), -1);
    }
    int ans = 0;
    while (ans < N && get(ans) == 0) ++ans;
    cout << (ans == N ? 0 : ans);
    return 0;
}