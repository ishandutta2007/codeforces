#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;
const ld EPS = 1e-4;

int n, k, x;
vector <int> es[N];
vector <pair<int, int> > ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        es[x].push_back(i);
    }
    if (es[0].size() != 1) {
        cout << -1;
        return 0;
    }

    int cur = 0;
    int cap = k;

    for (int i = 1; i < n; i++) {
        if (i == 2) k--;
        cur = 0;
        cap = k;
        for (int j = 0; j < es[i].size(); j++) {
            if (cur >= es[i - 1].size() || k == 0) {
                cout << -1;
                return 0;
            }
            ans.push_back(make_pair(es[i - 1][cur] + 1, es[i][j] + 1));
            cap--;
            if (cap == 0) {
                cap = k;
                cur++;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < int(ans.size()); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}