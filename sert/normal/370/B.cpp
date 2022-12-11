#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e2 + 7;
const int inf  = 1e9;

vector <int> es[N];
bool u[N], fail, ans[N];
int n, k, x;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            es[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) u[j] = false;
        for (int j = 0; j < es[i].size(); j++) u[es[i][j]] = true;
        for (int j = 0; j < n; j++)
        if (i != j) {
            fail = true;
            for (int ii = 0; ii < es[j].size(); ii++)
                fail &= u[es[j][ii]];
            ans[i] |= fail;
        }
    }

    for (int i = 0; i < n; i++)
        if (ans[i])
            cout << "NO\n";
        else
            cout << "YES\n";

    return 0;
}