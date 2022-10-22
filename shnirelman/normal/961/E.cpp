#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = N * 30;
const int LOG = 30;

int t[N];

void upd(int i, int x) {
    for(; i < N; i |= (i + 1))
        t[i] += x;
}

int get(int i) {
    if(i < 0)
        return 0;
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1) {
        res += t[i];
//        cout << "get for " << i << ' '<< t[i] << endl;
    }

    return res;
}

int a[N];
vector<int> g[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = min(a[i] - 1, n - 1);
    }

    for(int i = 0; i < n; i++) {
        g[a[i]].push_back(i);
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        upd(a[i], 1);
//        cout << i << ' ' << a[i] << endl;
//        for(int j = 0; j <= n; j++)
//            cout << t[j] << ' ';
//        cout << endl;
        for(auto x : g[i]) {
            ans += get(n - 1) - get(x - 1);
//            cout << x << ' ' << get(n - 1) - get(x) << ' ' << get(n) << ' ' << get(x) << endl;
        }
    }

    for(int i = 0; i < n; i++)
        ans -= (a[i] >= i);

    cout << ans / 2 << endl;
}