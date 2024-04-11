#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

int n, x, t, h, m, xx;
vector<pair<int, int> > a[2];
bool u[N][2];
int he;

int solve(int p) {
    int ps = -1;
    int mx = -1;
    for (int i = 0; i < a[p].size(); i++)
        if (a[p][i].first <= x && a[p][i].second > mx && !u[i][p]) {
            mx = a[p][i].second;
            ps = i;
        }
    if (ps == -1)
        return he;
    he++;
    u[ps][p] = true;
    x += mx;
    return solve(1 - p);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> x;
    xx = x;
    for (int i = 0; i < n; i++) {
        cin >> t >> h >> m;
        a[t].push_back(make_pair(h, m));
    }
    int ans = solve(0);
    for (int i = 0; i < N; i++)
        u[i][0] = u[i][1] = false;
    x = xx;
    he = 0;
    ans = max(ans, solve(1));
    cout << ans;
    //return 0;
}