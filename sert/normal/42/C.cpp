#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 16;

int main() {
#ifdef SERT
    freopen("../in", "r", stdin);
#endif
    map<array<int, 4>, int> dp;
    map<array<int, 4>, int> pr;
    array<int, 4> st = {1, 1, 1, 1};
    dp[st] = 0;
    queue<array<int, 4>> q;
    q.push(st);
    while (!q.empty()) {
        const auto &v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = (i + 1) % 4;
            if (min(v[i], v[nx]) > 1) {
                auto w = v;
                w[i]--; w[nx]--;
                if (!dp.count(w)) {
                    dp[w] = dp[v] + 1;
                    pr[w] = i;
                    q.push(w);
                }
            }
            if (max(v[i], v[nx]) * 2 <= MX) {
                auto w = v;
                w[i] *= 2; w[nx] *= 2;
                if (!dp.count(w)) {
                    dp[w] = dp[v] + 1;
                    pr[w] = 4 + i;
                    q.push(w);
                }
            }
        }
    }

    array<int, 4> a{};
    for (int i = 0; i < 4; i++) cin >> a[i];
    auto mx = [](const array<int, 4> &a) { return *max_element(a.begin(), a.end()); };
    mt19937 rnd(3431);
    vector<int> perm = {0, 1, 2, 3};
    while (mx(a) > MX / 2) {
        shuffle(perm.begin(), perm.end(), rnd);
        bool ok = false;
        for (int j = 0; !ok && j < 4; j++) {
            int i = perm[j];
            int nx = (i + 1) % 4;
            if (a[i] % 2 == 0 && a[nx] % 2 == 0) {
                cout << "/" << i + 1 << "\n";
                a[i] /= 2;
                a[nx] /= 2;
                ok = true;
            }
        }
        if (ok) continue;
        for (int j = 0; j < 4; j++) {
            int i = perm[j];
            int n1 = (i + 1) % 4;
            int ss = -1;
            if (a[i] % 2 && a[n1] % 2) ss = i;
            if (a[i] % 2 == 0) ss = n1;
            if (ss != -1) {
                cout << "+" << ss + 1 << "\n";
                a[ss]++;
                a[(ss + 1) % 4]++;
                break;
            }
        }
    }

    while (mx(a) > 1) {
        int val = pr[a];
        int n1 = val % 4;
        int n2 = (val + 1) % 4;
        if (val < 4) { a[n1]++; a[n2]++; cout << "+" << val % 4 + 1 << "\n"; }
        else { a[n1] /= 2; a[n2] /= 2; cout << "/" << val % 4 + 1 << "\n"; }
    }
}