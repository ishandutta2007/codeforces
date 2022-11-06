#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

const i64 MOD = 1000000007;

i64 Qipow(i64 B, i64 T)
{
    i64 A = 1;
    for (; T; T >>= 1)
        {
            if (T & 1) A = (A * B) % MOD;
            B = (B * B) % MOD;
        }
    return A;
}

i64 Comb[101][101], Rate[101], Bonus[101][101];
i64 N, M, K, i, j, d;

void Precombination()
{
    Comb[0][0] = 1;
    i64 i, j;
    fortodo(i, 1, N)
        {
            fortodo(j, 0, i) Comb[i][j] = 0;
            fortodo(j, 0, i - 1)
                {
                    Comb[i][j] += Comb[i - 1][j];
                    Comb[i][j + 1] += Comb[i - 1][j];
                }
            fortodo(j, 0, i) Comb[i][j] %= MOD;
        }
}

i64 DP[101][10001];

int main()
{
    cin >> N >> M >> K;
    Precombination();
    fortodo(i, 1, N) Rate[i] = M / N;
    fortodo(i, 1, (M % N)) Rate[i]++;
    fortodo(i, 1, N)
        fortodo(j, 0, N)
            Bonus[i][j] = Qipow(Comb[N][j], Rate[i]);
    int SQRN = N * N;
    fortodo(i, 0, N)
        fortodo(j, 0, SQRN)
            DP[i][j] = 0;
    DP[0][0] = 1;
    fortodo(i, 1, N)
        {
            i64 IN = i * N;
            fortodo(j, 0, IN)
                {
                    fortodo(d, 0, N)
                        if (d <= j)
                            DP[i][j] += (DP[i - 1][j - d] * Bonus[i][d]) % MOD;
                        else
                            break;
                    DP[i][j] %= MOD;
                }
        }
    cout << DP[N][K] << endl;
}