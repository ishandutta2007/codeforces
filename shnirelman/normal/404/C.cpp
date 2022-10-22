#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 1e5 + 13;

pii a[N];
queue<pii> b[N];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f;
        a[i].s = i;
        b[a[i].f].push({int(a[i].f > 0), i});
        if(b[a[i].f].front().f >= k)
            b[a[i].f].pop();
    }

    sort(a, a + n);

    if(a[1].f == 0 || a[0].f != 0) {
        cout << -1;
        return 0;
    }

    vector<pii> ans;
    for(int i = 1; i < n; i++) {
        if(b[a[i].f - 1].empty()) {
            cout << -1;
            return 0;
        }

        ans.emplace_back(b[a[i].f - 1].front().s, a[i].s);
        b[a[i].f - 1].front().f++;
        if(b[a[i].f - 1].front().f == k)
            b[a[i].f - 1].pop();
    }

    cout << ans.size() << endl;
    for(auto p : ans)
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
}