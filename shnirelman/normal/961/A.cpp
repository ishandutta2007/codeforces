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
const int N = 200 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> m >> n;

    vector<int> c(m, 0);
    for(int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        c[x - 1]++;
    }

    int mn = INF;
    for(auto x : c)
        mn = min(mn, x);

    cout << mn << endl;
}