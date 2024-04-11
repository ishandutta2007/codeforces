#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1234;
const int INF = 1e9;

map <int, pair<int, int> > f;
map <int, pair<int, int> > :: iterator it;
int n, half, ans = INF, c1, c2;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        f[c1].first++;
        if (c2 != c1)
            f[c2].second++;
    }
    half = (n + 1) / 2;
    for (it = f.begin(); it != f.end(); it++) {
        if (it->second.first + it->second.second >= half) {
            ans = min(ans, half - it->second.first);
        }
    }
    if (ans == INF)
        cout << -1;
    else
        cout << max(ans, 0);

    //while(true);
}