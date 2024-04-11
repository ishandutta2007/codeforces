#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000007;
int N, i, j, P0, PC[2001], mpc;
i64 A[501], s, Fact[20001];
map<i64,int> Primes;
map<i64,int>::iterator p;

i64 Inv(i64 B)
{
    i64 A = 1;
    for (i64 T = MOD - 2; T; T >>= 1)
        {
            if (T & 1) A = (A * B) % MOD;
            B = (B * B) % MOD;
        }
    return A;
}

i64 Combin(int N, int M)
{
    return ((Fact[N] * Inv(Fact[M])) % MOD) * Inv(Fact[N - M]) % MOD;
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    Primes.clear();
    fortodo(i, 1, N)
        {
            for (s = 2; s * s <= A[i]; s++)
                while (A[i] % s == 0)
                    {
                        Primes[s]++;
                        A[i] /= s;
                    }
            if (A[i] > 1) Primes[A[i]]++;
        }
    P0 = 0;
    for (p = Primes.begin(); p != Primes.end(); p++)
        PC[++P0] = p->second;   
    mpc = 0;
    fortodo(i, 1, P0) mpc = max(mpc, PC[i]);
    mpc += N;
    Fact[0] = 1;
    fortodo(i, 1, mpc) Fact[i] = (Fact[i - 1] * i) % MOD;
    i64 ANS = 1;
    fortodo(i, 1, P0) ANS = (ANS * Combin(N + PC[i] - 1, N - 1)) % MOD;
    cout << ANS << endl;
}