#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e5 + 13;
const int LOGN = 30;

int a[N], dp[N];
int mn[2][N * 4];

void build(int v, int l, int r) {
    mn[0][v] = mn[1][v] = INF;

    if(r - l == 1)
        return;

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
}

void upd(int v, int l, int r, int qi, int x, int ind) {
    if(r - l == 1) {
        mn[ind][v] = x;
        return;
    }

    int m = (l + r) / 2;

    if(qi < m)
        upd(v * 2 + 1, l, m, qi, x, ind);
    else
        upd(v * 2 + 2, m, r, qi, x, ind);

    mn[ind][v] = min(mn[ind][v * 2 + 1], mn[ind][v * 2 + 2]);
}

int get(int v, int l, int r, int ql, int qr, int ind) {
//    cout << "get " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << ind << endl;
    if(ql >= r || qr <= l)
        return INF;

    if(ql <= l && r <= qr)
        return mn[ind][v];

    int m = (l + r) / 2;

    return min(get(v * 2 + 1, l, m, ql, qr, ind), get(v * 2 + 2, m, r, ql, qr, ind));
}

/*
1
2
1 2
*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(0, 0, n);


    stack<int> st1, st2;
    st1.push(0);
    st2.push(0);

    upd(0, 0, n, 0, 0, 0);
    upd(0, 0, n, 0, 0, 1);

//    stack<int> mn1, mn2;
//    mn1.push(0);
//    mn2.push(0);

    for(int i = 1; i < n; i++) {
//        cout << i << endl;
        while(!st1.empty() && a[st1.top()] > a[i]) {
            upd(0, 0, n, st1.top(), INF, 0);
            st1.pop();
//            mn1.pop();
        }
//cout << i << endl;
        while(!st2.empty() && a[st2.top()] < a[i]) {
            upd(0, 0, n, st2.top(), INF, 1);
            st2.pop();
//            mn2.pop();
        }
//cout << i << ' ' << st2.size() << ' ' << st2.size() << endl;
        dp[i] = 1 + min(get(0, 0, n, (!st1.empty() ? st1.top() + 1 : 0), i, 1),
                        get(0, 0, n, (!st2.empty() ? st2.top() + 1 : 0), i, 0));

//cout << i << endl;
        st1.push(i);
        upd(0, 0, n, i, dp[i], 0);

        st2.push(i);
        upd(0, 0, n, i, dp[i], 1);
    }

    cout << dp[n - 1] << '\n';
//    cout << dp[n - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}