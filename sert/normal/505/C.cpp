#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 30101;
const int M = 3e7;
const ld EPS = 1e-4;

unordered_map <int, int> m;
int a[N], suf[N];
int n, x, cur, l;
int d[M];

int go(int v) {
    //cerr << v << "\n";
    //if (d.find(v) != d.end())
      //  return d[v];
    if (v < M) {
        if (d[v] != -1)
            return d[v];
    } else {
        if (m.find(v) != m.end())
            return m[v];
    }


    int p = v % N;
    int l = v / N;

    if (l <= 2)
        return (v < M ? d[v] = suf[p] : m[v] = suf[p]);

    int res = 0;
    for (int nl = l - 1; nl <= l + 1 && p + nl <= 30000; nl++)
        res = max(res, go(p + nl + N * nl));
    return (v < M ? d[v] = a[p] + res : m[v] = a[p] + res);
}

int main() {
    for (int i = 0; i < M; i++)
        d[i] = -1;
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 30000; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    cout << go(N * l + l);

    return 0;
}