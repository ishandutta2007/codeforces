#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

//void unit(int x, int y) {
//    x = getp(x);
//    y = getp(y);
//
//    if(x == y)
//        return;
//
//    if(sz[x] < sz[y])
//        swap(x, y);
//
//    sz[x] += sz[y];
//    p[y] = x;
//}

set<int> st[N];
int a[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
        p[i] = i;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;

        st[x].insert(i);
        a[i] = x;
    }

    int res = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1])
            res++;
    }
//
//    for(int i = 0;i < m; i++) {
//        for(auto x : st[i])
//            cout << x << ' ';
//        cout << endl;
//    }

    cout << res << endl;

    for(int i = 1; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        x = getp(x);
        y = getp(y);
//        unit(x, y);

        if(st[x].size() < st[y].size()) {
            swap(x, y);
        }
        p[y] = x;
//cout << x << ' ' << y << endl;
        for(auto z : st[y]) {
//            cout << "z " << z << endl;
            if(st[x].count(z - 1))
                res--;
            if(st[x].count(z + 1))
                res--;
        }

        for(auto z : st[y]) {
            st[x].insert(z);
        }

        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}