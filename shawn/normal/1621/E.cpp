#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, sk = 0;
        cin >> n >> m;
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai;
        ranges::sort(a);
        vector b(m, vector<LL>());
        vector<LL> sum(m);
        vector<int> st(m);
        for (int i = 0; i < m; i += 1) {
            int k;
            cin >> k;
            st[i] = sk;
            sk += k;
            b[i].resize(k);
            for (LL& bij : b[i]) {
                cin >> bij;
                sum[i] += bij;
            }
        }
        vector<int> ans(sk);
        multiset<LL> ms;
        for (LL x : a) ms.insert(x);
        function<void(int, int)> DFS = [&](int L, int R) {
            int M = (L + R) / 2;
            if (L == R) {
                LL mx = *ms.rbegin();
                for (int i = 0; i < b[M].size(); i += 1)
                    if (mx * (b[M].size() - 1) >= sum[M] - b[M][i])
                        ans[st[M] + i] = 1;
                return;
            }
            {
                vector<LL> rm;
                int ok = 1;
                for (int i = M + 1; i <= R; i += 1) {
                    LL x = (sum[i] + b[i].size() - 1) / b[i].size();
                    auto it = ms.lower_bound(x);
                    if (it == ms.end()) {
                        ok = 0;
                        break;
                    }
                    rm.push_back(*it);
                    ms.erase(it);
                }
                if (ok) DFS(L, M);
                for (LL x : rm) ms.insert(x);
            }
            {
                vector<LL> rm;
                int ok = 1;
                for (int i = L; i <= M; i += 1) {
                    LL x = (sum[i] + b[i].size() - 1) / b[i].size();
                    auto it = ms.lower_bound(x);
                    if (it == ms.end()) {
                        ok = 0;
                        break;
                    }
                    rm.push_back(*it);
                    ms.erase(it);
                }
                if (ok) DFS(M + 1, R);
                for (LL x : rm) ms.insert(x);
            }
        };
        DFS(0, m - 1);
        for (int x : ans) cout << x;
        cout << "\n";
    }
    return 0;
}