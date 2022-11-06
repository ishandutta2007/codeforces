#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int P, Q, U, V;
int S[100001];

int GetInt()
{
    P = ((P ^ Q) + (Q << 16) + (Q >> 16)) & 2147483647;
    Q = ((Q ^ P) + (P << 16) + (P >> 16)) & 2147483647;
    return P ^ Q;
};

int GetRnd(int P)
{
    return GetInt() % P;
};

int N, M, e[200001][2], enxt[200001], head[100001], ec;
int i, j, k;

void REGI(int u, int v)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v;
    enxt[ec] = head[u]; head[u] = ec; 
};

bool Find(int u, int v)
{
    int K = head[u];
    while (K != -1)
        {
            if (e[K][1] == v) return true;
            K = enxt[K];
        }; 
    return false;
};

void Shuffle(int Strength)
{
    int i, X, Y; 
    fortodo(i, 1, Strength)
        {
            X = GetRnd(N) + 1;
            Y = GetRnd(N) + 1;
            swap(S[X], S[Y]);
        };
};

int ANS[100001][2], CNT;

bool RndChk()
{
    Shuffle(max(N / 5, 2));
    CNT = 0;
    int L, R, i;
    L = 1;
    fortodo(R, 1, N - 1)
        {
            if (Find(S[R], S[R + 1]))
                {
                    if (L < R - 1)
                        if (!Find(S[L], S[R]))
                            {
                                CNT++;
                                ANS[CNT][0] = S[L];
                                ANS[CNT][1] = S[R];
                            };
                    L = R + 1;
                }
            else
                {
                    CNT++;
                    ANS[CNT][0] = S[R];
                    ANS[CNT][1] = S[R + 1];
                };
        };
    if ((L < N - 1) && (!Find(S[L], S[N])))
        {
            CNT++;
            ANS[CNT][0] = S[L];
            ANS[CNT][1] = S[R];
        };
    if (CNT < M) return false;
    fortodo(i, 1, M) printf("%d %d\n", ANS[i][0], ANS[i][1]);
    return true;
};

int main()
{
    P = 316000;
    Q = 19970530;
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) head[i] = -1;
    ec = 0;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &U, &V);
            REGI(U, V); REGI(V, U);
        };
    fortodo(i, 1, N) S[i] = i;
    Shuffle(N / 3);
    fortodo(i, 0, 299)
        if (RndChk())
            return 0;
    printf("-1\n");
    return 0;
};