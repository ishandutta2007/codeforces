#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int CS;

int N, M, i, j;
int S[110000][2], F[110000][14];
int Os, Opt[7001][4];
int Lyrcnt[7001];

void Constr()
{
    int Lyr, i, Cntpre, Cntths;
    CS = 2; S[1][0] = 1; S[1][1] = 2;
    Lyrcnt[1] = 1;
    Lyrcnt[2] = 2;
    fortodo(Lyr, 3, N)
        {
            Lyrcnt[Lyr] = Lyrcnt[Lyr - 1];
            fortodo(i, Lyrcnt[Lyr - 2] + 1, Lyrcnt[Lyr - 1])
                if (i == (i & (-i)))
                    {
                        S[i][0] = ++Lyrcnt[Lyr];
                        S[i][1] = ++Lyrcnt[Lyr];
                    }
                else
                    {
                        S[i][0] = 0;
                        S[i][1] = ++Lyrcnt[Lyr];
                    }
        }
    CS = Lyrcnt[N];
}

void Gettable()
{
    int i, j;
    fortodo(i, 1, CS)
        fortodo(j, 0, 1)
            if (S[i][j])
                F[S[i][j]][0] = i;
    fortodo(i, 0, 13) F[1][i] = 1;
    fortodo(i, 2, CS)
        fortodo(j, 1, 13)
            F[i][j] = F[F[i][j - 1]][j - 1];
}

int Orz, Targlyr, Targverti, NL, NR, DT;

int Getance(int X, int Lyr)
{
    int i;
    for (i = 13; i >= 0; i--)
        if ((1 << i) <= Lyr)
            {
                Lyr -= 1 << i;
                X = F[X][i];
            }
    return X;
}

set<int> Ans;

int main()
{
    scanf("%d%d", &N, &M);
    Constr();
    Gettable();
    Os = 0;
    fortodo(i, 1, M)
        {
            scanf("%d", &Orz);
            if (Orz == 1)
                {
                    Os++;
                    fortodo(j, 0, 3) scanf("%d", &Opt[Os][j]);
                }
            else
                {
                    Ans.clear();
                    scanf("%d%d", &Targlyr, &Targverti);
                    fortodo(j, 1, Os)
                        if (Targlyr <= Opt[j][0])
                            {
                                DT = Opt[j][0] - Targlyr;
                                NL = Getance(Opt[j][1], DT);
                                NR = Getance(Opt[j][2], DT);
                                if ((NL <= Targverti) && (Targverti <= NR))
                                    Ans.insert(Opt[j][3]);
                            }
                    printf("%d\n", Ans.size());
                }
        }
}