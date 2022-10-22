#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;

int a[N];
li p[N], s[N];
int lf[N], rg[N];

li tp[N * 4], ts[N * 4];

void build(int v, int l, int r) {
    if(r - l == 1) {
        tp[v] = p[l];
        ts[v] = s[l];
        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    tp[v] = min(tp[v * 2 + 1], tp[v * 2 + 2]);
    ts[v] = min(ts[v * 2 + 1], ts[v * 2 + 2]);
}

li get(int v, int l, int r, int ql, int qr, bool pr) {
    if(ql >= r || qr <= l)
        return INF64;

    if(ql <= l && r <= qr)
        return (pr ? tp[v] : ts[v]);

    int m = (l + r) / 2;
    return min(get(v * 2 + 1, l, m, ql, qr, pr), get(v * 2 + 2, m, r, ql, qr, pr));
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i <= n; i++) {
        p[i] = s[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }

    for(int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + a[i];
    }

    build(0, 0, n + 1);

    {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[st.top()] < a[i])
                st.pop();

            lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

    {
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && a[st.top()] <= a[i])
                st.pop();

            rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << p[i + 1] << ' ' << mnp[i] << ' ' << s[i] << ' ' << mns[i + 1] << endl;
//        cout << i << ' ' << lf[i] << ' ' << rg[i] << ' ' << get(0, 0, n, lf[i] + 1, i + 1, true) << ' ' << get(0, 0, n, i + 1, rg[i] + 1, false) << endl;
//        if(a[i] < p[n] - mnp[i] - mns[i + 1]) {
        if(a[i] < p[n] - get(0, 0, n + 1, lf[i] + 1, i + 1, true) - get(0, 0, n + 1, i + 1, rg[i] + 1, false)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}