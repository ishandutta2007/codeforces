#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, b[N];
pair<int, int> a[N];
int lst, cur;
int p[N], s[N], ls[N];

int t[N * 8];
void add(int v, int l, int r, int p, int x) {
    if (l + 1 == r) {
        t[v] += x;
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, x);
    else
        add(v * 2 + 2, m, r, p, x);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int sum(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return sum(v * 2 + 1, l, m, L, R) + sum(v * 2 + 2, m, r, L, R);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; a[i].second = i++)
        scanf("%d", &a[i].first);
    sort(a, a + n);
    cur = a[0].first;
    a[0] = make_pair(a[0].second, 0);
    for (int i = 1; i < n; i++) {
        lst = cur;
        cur = a[i].first;
        a[i] = make_pair(a[i].second, a[i - 1].second + int(lst < cur));
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        b[i] = a[i].second;

    //for (int i = 0; i < n; i++) cerr << b[i] << " "; cerr << "\n";
    for (int i = 0; i < n; i++)
        ls[i] = -1;
    for (int i = 0; i < n; ls[b[i]] = i++)
        p[i] = (ls[b[i]] == -1 ? 1 : 1 + p[ls[b[i]]]);
    for (int i = 0; i < n; i++)
        ls[i] = -1;
    s[n] = -1;
    long long ans = 0;
    for (int i = n - 1; i >= 0; ls[b[i]] = i--) {
        ans += sum(0, 0, n + 1, 0, p[i]);
        s[i] = (ls[b[i]] == -1 ? 1 : 1 + s[ls[b[i]]]);
        add(0, 0, n + 1, s[i], 1);
    }

    cout << ans;



    return 0;
}