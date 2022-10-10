#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int n, p[MAXN], c[MAXN], take[MAXN];

int best(vector<int> &v) {
    int m = v.size();
    vector<int> divs;
    for(int d = 1; d * d <= m; d++) {
        if(m % d)
            continue;
        divs.push_back(d);
        if(m / d > d)
            divs.push_back(m/d);
    }
    int bst = m;
    for(auto d : divs) {
        bool good = false;
        for(int i = 0; i < d; i++) {
            int col = c[v[i]];
            bool broke = false;
            for(int j = i + d; j < m; j += d) {
                if(c[v[j]] != col) {
                    broke = true;
                    break;
                }
            }
            if(broke)
                continue;
            good = true;
            break;
        }
        if(good)
            bst = min(bst, d);
    }
    return bst;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        take[i] = 0;
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(!take[i]) {
            vector<int> v;
            int x = i;
            do {
                v.push_back(x);
                take[x] = 1;
                x = p[x];
            } while(x != i);
            ans = min(ans, best(v));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}