#include <bits/stdc++.h>
using namespace std;

const int MAX_LOG = 30;

int main() {
    cin.tie();
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++)
        cin >> L[i] >> R[i], L[i]--;

    vector<int> ans(MAX_LOG, 0);
    ans[0] = N;
    vector<pair<int, int>> ord, nord;
    vector<int> imos(2 * N + 2, 0);
    for (int i = 0; i < N; i++) {
        ord.emplace_back(i, 0);
        ord.emplace_back(i, 1);
    }
    vector<int> LL(N), RR(N);

    for (int k = 1; k < MAX_LOG; k++) {
        int len = 1 << k;
        int mask = len - 1;
        vector<vector<pair<int, int>>> d(2);
        for (auto p : ord) {
            int idx = p.first, box = p.second;
            int val = (box == 0 ? L[idx] : R[idx]);
            d[val >> (k - 1) & 1].emplace_back(p);
        }
        for (auto p : d[0])
            nord.emplace_back(p);
        for (auto p : d[1])
            nord.emplace_back(p);
        swap(ord, nord);
        nord.clear();
        int pre = 0, cur = 0;
        for (int i = 0; i < 2 * N; i++) {
            auto p = ord[i];
            int idx = p.first, box = p.second;
            int val = (box == 0 ? L[idx] & mask : R[idx] & mask);
            if (val != pre) {
                cur++;
                pre = val;
            }
            if (box == 0)
                LL[idx] = cur;
            else
                RR[idx] = cur;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (R[i] - L[i] >= len) {
                cnt++;
                continue;
            }
            int l = LL[i], r = RR[i];
            if (l < r) {
                imos[l]++;
                imos[r]--;
            } else {
                imos[l]++;
                imos[2 * N + 1]--;
                imos[0]++;
                imos[r]--;
            }
        }
        for (int i = 0; i < 2 * N + 2; i++) {
            ans[k] = max(ans[k], imos[i]);
            if (i + 1 < 2 * N + 2)
                imos[i + 1] += imos[i];
            imos[i] = 0;
        }
        ans[k] += cnt;
    }
    auto query = [&](int W) -> int {
        for (int i = 0; i < MAX_LOG; i++) {
            if (W >> i & 1) {
                return ans[i];
            }
        }
    };

    int Q;
    cin >> Q;
    for (; Q--;) {
        int W;
        cin >> W;
        cout << query(W) << "\n";
    }
}