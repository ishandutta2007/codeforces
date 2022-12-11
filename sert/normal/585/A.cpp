#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, cur, v[N], d[N], p[N], w, sm, kl;
vector <int> ans;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }
    cur = 0;

    for (int i = 0; i < n; i++) {
        if (p[i] >= 0) {
            ans.push_back(i + 1);
            cur = v[i] + 1;
            sm = 0;
            for (int j = i + 1; j < n; j++) {
                if (p[j] < 0) continue;
                if (cur) cur--;
                p[j] -= (sm + cur);
                if (p[j] < 0) sm = min(sm + d[j], 10000000);
            }
        }
    }

    cout << ans.size() << "\n";
    for (int v: ans)
        cout << v << " ";


    return 0;
}