#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const long double EPS = 1e-12;

ll n, ans[N], c;
priority_queue <pair<int, pair<int, int> > > q;
pair<int, int> v;
bool u[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    n *= 2;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++) {
            cin >> c;
            q.push(make_pair(c, make_pair(j, i)));
        }

    while (!q.empty()) {
        v = q.top().second;
        q.pop();
        if (u[v.first] || u[v.second])
            continue;
        ans[v.first] = v.second + 1;
        ans[v.second] = v.first + 1;
        u[v.first] = u[v.second] = true;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}