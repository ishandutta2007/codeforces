#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j;
char S[1000010];

struct Braquence
{
    int Matched, LR, RL;
    Braquence() {}
    Braquence(int m, int lr, int rl)
    {
        Matched = m;
        LR = lr; RL = rl;
    }
    Braquence operator +(Braquence Snd)
    {
        if (RL > Snd.LR)
            return Braquence(Matched + Snd.Matched + 2 * Snd.LR, LR, Snd.RL + RL - Snd.LR);
        else
            return Braquence(Matched + Snd.Matched + 2 * RL, LR + Snd.LR - RL, Snd.RL);
    }
};

Braquence SEG[5000001];

void BUILD(int Nid, int L, int R)
{
    if (L == R)
        SEG[Nid] = (S[L] == '(') ? Braquence(0, 0, 1) : Braquence(0, 1, 0);
    else
        {
            int Mid = (L + R) / 2;
            BUILD(Nid * 2, L, Mid);
            BUILD(Nid * 2 + 1, Mid + 1, R);
            SEG[Nid] = SEG[Nid * 2] + SEG[Nid * 2 + 1];
        }
}

Braquence QUERY(int Nid, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return SEG[Nid];
    int Mid = (L + R) / 2;
    if (r <= Mid) return QUERY(Nid * 2, L, Mid, l, r);
    if (l > Mid) return QUERY(Nid * 2 + 1, Mid + 1, R, l, r);
    return QUERY(Nid * 2, L, Mid, l, Mid) + QUERY(Nid * 2 + 1, Mid + 1, R, Mid + 1, r);
}

int M, Li, Ri;

int main()
{
    scanf("%s", S + 1);
    N = strlen(S + 1);
    BUILD(1, 1, N);
    for (scanf("%d", &M); M; M--)
        {
            scanf("%d%d", &Li, &Ri);
            printf("%d\n", QUERY(1, 1, N, Li, Ri).Matched);
        }
}