#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXS = 100010;

char S[MAXS];
int N, nx[MAXS], cnt[MAXS];

void Getnext()
{
    int pa, pb;
    nx[1] = pb = 0;
    fortodo(pa, 2, N)
        {
            while ((pb) && (S[pa] != S[pb + 1])) pb = nx[pb];
            if (S[pa] == S[pb + 1]) pb++;
            nx[pa] = pb;
        }
}

void AnswerIt(int x, int dep)
{
    if (x)
        {
            AnswerIt(nx[x], dep + 1);
            printf("%d %d\n", x, cnt[x]);
        }
    else
        printf("%d\n", dep);
}

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    Getnext();
    int i;
    fortodo(i, 0, N) cnt[i] = 1;
    for (int i = N; i; i--) cnt[nx[i]] += cnt[i];
    AnswerIt(N, 0);
}