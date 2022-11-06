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

int N, i, sig;
char S[1010];
int Las[26], Cnt[26];

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    fortodo(i, 0, 25) Las[i] = Cnt[i] = 0;
    fortodo(i, 1, N)
        {
            sig = S[i] - 'A';
            if (Las[sig] == 0)
                {
                    Las[sig] = i;
                    Cnt[sig] = 1;
                }
            else
                if ((Las[sig] ^ i) & 1)
                    {
                        Las[sig] = i;
                        Cnt[sig]++;
                    }
        }
    int ANS = 0;
    fortodo(i, 0, 25) ANS = max(ANS, Cnt[i]);
    printf("%d\n", ANS);
}