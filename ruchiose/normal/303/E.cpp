// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#include<vector> 

const int MAXN = 85;

int N, L[MAXN], R[MAXN];
vector<int> Edpts;

double dp[MAXN][MAXN];

int main()
{
    scanf("%d", &N);
    Edpts.clear();
    int i;
    fortodo(i, 1, N)
        {
            scanf("%d%d", &L[i], &R[i]);
            Edpts.push_back(L[i]);
            Edpts.push_back(R[i]);
        }
    sort(Edpts.begin(), Edpts.end());
    Edpts.resize(unique(Edpts.begin(), Edpts.end()) - Edpts.begin());
    int M = Edpts.size();
    int p;
    fortodo(p, 1, N)
        {
            double ans[MAXN];
            fortodo(i, 0, N) ans[i] = 0;
            int s;
            fortodo(s, 1, M - 1)
                {
                    #define l Edpts[s - 1]
                    #define r Edpts[s]
                    if (r <= L[p]) continue;
                    if (l >= R[p]) continue;
                    int mx = 0;
                    int c, i, j;
                    fortodo(i, 0, N)
                        fortodo(j, 0, N)
                            dp[i][j] = 0;
                    dp[0][0] = (r - l) * 1.0 / (R[p] - L[p]);
                    int ob = 0, os = 0;
                    fortodo(c, 1, N)
                        if (c != p)
                            {
                                if (R[c] <= l)
                                    {
                                        os++;
                                        continue;
                                    }
                                if (L[c] >= r)
                                    {
                                        ob++;
                                        continue;
                                    }
                                double ir = (r - l) * 1.0 / (R[c] - L[c]);
                                double ib = max(l - L[c], 0) * 1.0 / (R[c] - L[c]);
                                double is = max(R[c] - r, 0) * 1.0 / (R[c] - L[c]);
                                for (i = mx + 1; i >= 0; i--)
                                    for (j = mx + 1 - i; j >= 0; j--)
                                        {
                                            dp[i][j] *= ir;
                                            if (i) dp[i][j] += dp[i - 1][j] * ib;
                                            if (j) dp[i][j] += dp[i][j - 1] * is;
                                        }
                                mx++;
                            }
                    for (i = os; i < N; i++)
                        for (j = ob; j < N - i; j++)
                            {
                                ans[i] -= dp[i - os][j - ob] / (N - i - j);
                                ans[N - j] += dp[i - os][j - ob] / (N - i - j);
                            }
                }
            for (i = N; i; i--) ans[i - 1] += ans[i];
            fortodo(i, 1, N) printf("%.8f%s", ans[i], (i == N) ? "\n" : " ");
        }
}