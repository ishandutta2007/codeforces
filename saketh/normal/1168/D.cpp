#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vi par(N);
    string elt(N, '.');
    vi depth(N);
    vvi child(N);
    vector<array<int, 26>> link(N);

    vi group(N);
    for (int i = 1; i < N; i++) {
        cin >> par[i] >> elt[i];

        child[--par[i]].push_back(i);
        depth[i] = depth[par[i]] + 1;
        group[i] = i;
        if (elt[i] != '?') link[i][elt[i] - 'a'] = 1;
    }

    int height = *max_element(all(depth));
    for (int& v : depth)
        v = height - v;

    for (int i = 0; i < N; i++) {
        if (child[i].empty() && depth[i] != 0) {
            while (Q--) {
                cout << "Fou\n";
            }
            return 0;
        }
    }

    for (int i = N - 1; i > 0; i--) {
        if (child[i].size() == 1) {
            int g = child[i][0];
            group[i] = g;
            for (int c = 0; c < 26; c++)
                link[g][c] += link[i][c];

            par[g] = par[i];
            for (int& v : child[par[i]]) {
                if (v == i) { v = g; break; }
            }
        }
    }

    vb ok(N, true);
    vector<array<int, 26>> dp(N);

    for (int i = N - 1; i >= 0; i--) {
        if (group[i] != i) continue;
        for (int j : child[i]) {
            for (int c = 0; c < 26; c++)
                dp[i][c] = max(dp[i][c], dp[j][c] + link[j][c]);
            ok[i] = ok[i] & ok[j];
        }
        int rsum = 0;
        for (int v : dp[i]) rsum += v;
        ok[i] = ok[i] & (rsum <= depth[i]);
    }

    for (int q = 0; q < Q; q++) {
        int i; char c;
        cin >> i >> c;
        --i;

        if (elt[i] != '?') link[group[i]][elt[i] - 'a']--;
        elt[i] = c;
        if (elt[i] != '?') link[group[i]][elt[i] - 'a']++;

        for (int v = group[i]; v > 0; v = par[v]) {
            fill(all(dp[par[v]]), 0);
            ok[par[v]] = true;
            for (int j : child[par[v]]) {
                for (int c = 0; c < 26; c++)
                    dp[par[v]][c] = max(dp[par[v]][c], dp[j][c] + link[j][c]);
                ok[par[v]] = ok[par[v]] & ok[j];
            }
            int rsum = 0;
            for (int r : dp[par[v]]) rsum += r;
            ok[par[v]] = ok[par[v]] & (rsum <= depth[par[v]]);
        }

        if (ok[0]) {
            int rsum = 0;
            for (int r : dp[0]) rsum += r;

            int ans = 0;
            for (int c = 0; c < 26; c++)
                ans += (c + 1) * (dp[0][c] + height - rsum);
            cout << "Shi " << ans << "\n";
        } else cout << "Fou\n";
    }

    return 0;
}