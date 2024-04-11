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

const int MAXN = 100010;

int N, Q;

struct BIT
{
    int V[MAXN];
    void init()
    {
        int i;
        fortodo(i, 1, N) V[i] = i & -i;
    }
    void att(int x, int v)
    {
        //printf("[%d] += %d\n", x, v);
        for (; x <= N; x += x & -x) V[x] += v;
    }
    int qry(int x)
    {
        //printf("call(%d)\n", x);
        int v = 0;
        for (; x; x -= x & -x) v += V[x];
        return v;
    }
};

BIT bit;
int W[MAXN];

void Moveto(int la, int ra, int lb, int rb)
{
    int i;
    fortodo(i, la + 1, ra)
        {
            int shad = rb - (i - la - 1);
            W[shad] += W[i];
            bit.att(shad, W[i]);
            bit.att(i, -W[i]);
            W[i] = 0;
        }
}

int main()
{
    scanf("%d%d", &N, &Q);
    int L = 0, R = N, rev = 0;
    bit.init();
    int i;
    fortodo(i, 1, N) W[i] = 1;
    for (; Q; Q--)
        {
            //printf("(%d, %d]\n", L, R);
            //fortodo(i, L + 1, R) printf("%d%s", W[i], (i == R) ? ";\n" : ",");
            int opt, l, r;
            scanf("%d", &opt);
            if (opt == 1)
                {
                    scanf("%d", &l);
                    int thsrev = (l > R - L - l) ? 1 : 0; 
                    if (thsrev) l = R - L - l;
                    rev ^= thsrev;
                    if (rev)
                        {
                            Moveto(R - l, R, R - l * 2, R - l);
                            R -= l;
                        }
                    else
                        {
                            Moveto(L, L + l, L + l, L + l * 2);
                            L += l;
                        }
                }
            else
                {
                    scanf("%d%d", &l, &r);
                    if (rev == 0)
                        {
                            l = L + l;
                            r = L + r;
                        }
                    else
                        {
                            int t = R - r;
                            r = R - l;
                            l = t;
                        }
                    printf("%d\n", bit.qry(r) - bit.qry(l));
                }
        }
}