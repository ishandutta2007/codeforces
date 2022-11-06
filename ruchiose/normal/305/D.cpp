// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 1000010;
const int MOD = int(1e+9) + 7;

int N, M, K;
int Pow2[MAXN];
vector<int> W;

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    Pow2[0] = 1;
    int i;
    fortodo(i, 1, N) Pow2[i] = (Pow2[i - 1] << 1) % MOD;
    W.clear();
    fortodo(i, 1, M)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u == v - 1) continue;
            if (u != v - 1 - K)
                {
                    printf("0\n");
                    return 0;
                }
            W.push_back(v);
        }
    sort(W.begin(), W.end());
    int ans = 0;
    fortodo(i, K + 2, N)
        {
            int r = min(N, i + K);
            if ((W.size()) && ((W.front() < i) || (W.back() > r))) continue;
            int free;
            if (W.size())
                free = (r - i) - (W.size() - (W.front() == i));
            else
                free = (r - i);
            (ans += Pow2[free]) %= MOD;
        }
    if (W.size() == 0) (ans += 1) %= MOD;
    printf("%d\n", ans);
}