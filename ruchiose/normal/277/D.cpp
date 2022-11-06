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

const int MAXN = 1010;
const int MAXT = 1570;
const int MAGNIFIER = 1000000;
const i64 MAGNIFIERL = 1000000LL;
const double MAGNIFIERF = 1000000.0;

int getPreciseProbablity()
{
    double g;
    scanf("%lf", &g);
    return int(g * MAGNIFIER + 0.23333);
}

struct Task
{
    int pFail, sSmall, sLarge, tSmall, tLarge;
    void get()
    {
        scanf("%d%d%d%d", &sSmall, &sLarge, &tSmall, &tLarge);
        pFail = getPreciseProbablity();
    }
};

bool operator < (const Task &lhs, const Task &rhs)
{
    return lhs.tLarge * 1LL * lhs.pFail * (MAGNIFIER - rhs.pFail) < rhs.tLarge * 1LL * rhs.pFail * (MAGNIFIER - lhs.pFail);
}

struct ansPair
{
    i64 expScore;
    d64 expPenalty;
    ansPair(i64 expScore = 0, d64 expPenalty = 0)
    {
        this->expScore = expScore;
        this->expPenalty = expPenalty;
    }
};

bool operator < (const ansPair &lhs, const ansPair &rhs)
{
    return (lhs.expScore == rhs.expScore) ? (lhs.expPenalty > rhs.expPenalty) : (lhs.expScore < rhs.expScore);
}

void upd(ansPair &lhs, ansPair rhs)
{
    if (lhs < rhs) lhs = rhs;
}

int N, T;
Task t[MAXN];
ansPair dp[MAXN][MAXT];

int main()
{
    scanf("%d%d", &N, &T);
    int i, j;
    fortodo(i, 1, N) t[i].get();
    sort(t + 1, t + N + 1);
    fortodo(i, 1, N)
        fortodo(j, 0, T)
            {
                upd(dp[i][j], dp[i - 1][j]);
                if (j + t[i].tSmall <= T)
                    upd(dp[i][j + t[i].tSmall], ansPair(dp[i - 1][j].expScore + MAGNIFIERL * t[i].sSmall, dp[i - 1][j].expPenalty + t[i].tSmall));
                if (j + t[i].tSmall + t[i].tLarge <= T)
                    upd(dp[i][j + t[i].tSmall + t[i].tLarge],
                        ansPair(dp[i - 1][j].expScore + MAGNIFIERL * t[i].sSmall + (MAGNIFIERL - t[i].pFail) * t[i].sLarge,
                                t[i].tSmall + (t[i].pFail / MAGNIFIERF * dp[i - 1][j].expPenalty) + (1 - (t[i].pFail / MAGNIFIERF)) * (j + t[i].tLarge)));
            }
    ansPair ans;
    fortodo(i, 0, T) upd(ans, dp[N][i]);
    printf("%.6f %.12f\n", ans.expScore / MAGNIFIERF, double(ans.expPenalty));
}