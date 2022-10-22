//#define _GLIBCXX_DEBUG
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
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pr[N], sz[N];

int getp(int x) {
    return (x == pr[x] ? x : pr[x] = getp(pr[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    pr[y] = x;
    sz[x] += sz[x];
}

int p[N];
int res[N];
vector<int> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        pr[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        unite(x, y);
    }

    for(int i = 0; i < n; i++) {
        a[getp(i)].push_back(i);
        b[getp(i)].push_back(p[i]);
    }

    for(int i = 0; i < n; i++) {
        sort(b[i].rbegin(), b[i].rend());
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++)
            res[a[i][j]] = b[i][j];
    }

    for(int i = 0; i < n; i++)
        cout << res[i] + 1 << ' ';
    cout << endl;
}