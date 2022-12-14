#include <bits/stdc++.h>
using namespace std;
int t, n, x, pos[55], a[55], *b[55];
vector<pair<int,int>> Q;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i], b[i] = &a[i];
        sort(b+1, b+n+1, [] (int *x, int *y) { return *x < *y; });
        for(int i=1; i<=n; ++i) *b[i] = i;
        for(int i=1; i<=n; ++i) pos[a[i]] = i;
        Q.clear();
        for(int i=1; i<=n; ++i) {
            if (pos[i] == i) continue;
            Q.emplace_back(i, pos[i]);
            for(int j=1; j<=n; ++j) if (i <= pos[j] && pos[j] < pos[i]) ++pos[j];
        }
        cout << Q.size() << '\n';
        for(auto[u, v] : Q) cout << u << ' ' << v << ' ' << v - u << '\n';
    }
}