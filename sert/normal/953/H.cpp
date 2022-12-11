#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e6 + 34;
int p[N][3];
vector<ll> es[3];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    string c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> c;
    for (int i = 0; i < n; i++) {
        int kk = 0;
        if (c[i] == 'R') kk = 0;
        if (c[i] == 'W') kk = 1;
        if (c[i] == 'O') kk = 2;
        es[kk].push_back(a[i]);
    }

    for (int j = 0; j < 3; j++) {
        sort(es[j].begin(), es[j].end());
        es[j].push_back(0);
        reverse(es[j].begin(), es[j].end());
        for (int i = 1; i < (int)es[j].size(); i++) {
            es[j][i] += es[j][i - 1];
        }
    }

    /*for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (int)es[i].size(); j++) cerr << es[i][j] << " "; cerr << "\n";
    }*/

    ll ans = -1;
    for (int org = 1; org <= min(k, (int)es[2].size() - 1); org++) {
        if (k - org == 0) continue;
        if ((int)es[0].size() > k - org) {
            ans = max(ans, es[2][org] + es[0][k - org]);
        }
        if ((int)es[1].size() > k - org) {
            ans = max(ans, es[2][org] + es[1][k - org]);
        }
    }
    cout << ans;

    return 0;
}