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

int Euclid(int a, int b)
{
    return (b) ? Euclid(b, a % b) : a;
}

int LCM(int a, int b)
{
    return a * b / Euclid(a, b);
}

i64 countStep(i64 x, i64 t, int k)
{
    i64 ans = 0;
    while (x > t)
        {
            i64 nx = x - 1, sx;
            int i;
            fortodo(i, 2, k)
                if ((sx = (x / i) * i) >= t)
                    nx = min(nx, sx);
            x = nx;
            ans++;
        }
    return ans;
}

i64 A, B;
int K, L;

int main()
{
    cin >> A >> B >> K;
    L = 1;
    for (int i = 2; i <= K; i++)
        L = LCM(L, i);
    i64 pck = max(0LL, (A - B) / L - 1);
    i64 ans = pck * countStep(L, 0, K) + countStep(A - pck * L, B, K);
    cout << ans << endl;
}