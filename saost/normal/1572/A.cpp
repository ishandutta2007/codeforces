#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
int t, n, deg[N];
vector<int> S[N];
priority_queue<int> Q, Q2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) S[i].clear();
        for(int i=1; i<=n; ++i) {
            deg[i] = 0;
            int w;
            cin >> w;
            while (w--) {
                int v; cin >> v;
                S[v].push_back(i);
                ++deg[i];
            }
        }
        for(int i=1; i<=n; ++i) if (!deg[i]) Q.push(-i);
        int dem = 0, timer = 0;
        while (true) {
            if (Q.empty()) break;
            ++timer;
            while (!Q.empty()) {
                ++dem;
                int u = -Q.top(); Q.pop();
                for(int v : S[u]) {
                    if (--deg[v] == 0) {
                        if (u < v) Q.push(-v);
                        else Q2.push(-v);
                    }
                }
            }
            Q.swap(Q2);
        }
        if (dem < n) cout << -1 << '\n'; else cout << timer << '\n';
    }
}