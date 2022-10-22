#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 112;

vector<int> g[N];
int d[N];
pii a[N];

void solve() {
    int n, k;
    cin >> n >> k;

//    for(int i = 0; i < n; i++) {
//        g[i].erase(g[i].begin(), g[i].end());
////        for(int j = 0; j < n; j++) {
////            d[i][j] = INF;
////        }
//    }

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(abs(a[i].f - a[j].f) + abs(a[i].s - a[j].s) <= k) {
                cnt++;
            }
        }

        if(cnt == n) {
            cout << 1 << endl;
            return;
        }
    }

   cout << -1 << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}