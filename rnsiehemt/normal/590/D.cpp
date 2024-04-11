#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 155, MaxS = 6000, inf = 1e9;

int N, K, S, v[MaxN], w[MaxN], ans, pre;
std::vector<std::vector<std::vector<int>>> dp;

int main()
{
    scanf("%d%d%d", &N, &K, &S);
    for (int i = 0; i < N; i++) scanf("%d", &v[i]);

    for (int i = 0; i < N; i++) w[i] = v[i];
    std::sort(w, w+K);
    for (int i = 0; i < K; i++) pre += w[i];

    dp.resize(K+2);
    for (auto &i : dp) {
        i.resize(N-K+2);
        for (auto &j : i) {
            j.resize(MaxS);
            for (int &k : j) k = inf;
        }
    }

    dp[0][0][0] = 0;
    for (int ii = 0; true; ii++) {
        int i = K-ii;
        if (i < 0) break;
        for (int jj = 0; true; jj++) {
            int j = K-1 + jj;
            if (j > N-1) break;
            for (int s = 0; s < MaxS; s++) {
                if (s <= S) domin(ans, dp[ii][jj][s]);
                if (i-1 >= 0 && j+1 < N && s + (j+1)-(i-1) < MaxS) {
                    domin(dp[ii+1][jj+1][s + (j+1)-(i-1)], dp[ii][jj][s] + v[j+1] - v[i-1]);
                }
                if (i-1 >= 0) domin(dp[ii+1][jj][s], dp[ii][jj][s]);
                if (j+1 < N) domin(dp[ii][jj+1][s], dp[ii][jj][s]);
            }
        }
    }
    printf("%d\n", pre+ans);
}