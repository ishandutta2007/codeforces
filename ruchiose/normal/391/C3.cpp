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

int N, K, W, i, j;
#define pii pair<int,int>
#define pn first
#define ef second
pii f[200010];
const i64 Linf = 0x7FFFFFFFFFFFFFFFll;
i64 ANS = Linf;

bool cmp_px(pii a, pii b) {return (a.pn < b.pn);}
bool cmp_py(pii a, pii b) {return (a.ef < b.ef);}

int S[200010];

pii Cruc[200010], Eas[200010];
int C0, E0;

i64 Mainprocess(int T)
{
    C0 = E0 = 0;
    int i;
    fortodo(i, 1, N)
        if ((f[i].pn >= T - 1) && (f[i].pn <= T))
            Cruc[++C0] = f[i];
        else
            Eas[++E0] = f[i];
    int R = W - ((T > 1) ? S[T - 2] : 0);
    sort(Cruc + 1, Cruc + C0 + 1, cmp_py);
    sort(Eas + 1, Eas + E0 + 1, cmp_py);
    int AE = T - R;
    if (AE < 0) return Linf;
    if (R < 0) return Linf;
    i64 RET = 0;
    int pc, pe; pc = pe = 0;
    fortodo(i, 1, T)
        if (((pe == AE) || (Cruc[pc + 1].ef <= Eas[pe + 1].ef)) && (pc < C0))
            RET += Cruc[++pc].ef;
        else
            RET += Eas[++pe].ef;
    return RET;
}

i64 Assistprocess(int T)
{
    i64 RET = 0;
    sort(f + 1, f + N + 1, cmp_py);
    int i;
    fortodo(i, 1, T) RET += f[i].ef;
    return RET;
}

int main()
{
    scanf("%d%d", &N, &K); W = N + 1 - K;
    fortodo(i, 1, N) scanf("%d%d", &f[i].pn, &f[i].ef);
    sort(f + 1, f + N + 1, cmp_px);
    int Bestrank = N + 1;
    fortodo(i, 1, N) if (f[i].pn <= N) Bestrank--;
    if (Bestrank > K)
        {
            printf("-1\n");
            return 0;
        }
    int Presum = 0;
    fortodo(i, 0, N)
        {
            while ((Presum < N) && (f[Presum + 1].pn <= i)) Presum++;
            S[i] = Presum;
        }
    fortodo(i, 1, N)
        if (S[i] >= W)
            break;
    int U = i;
    ANS = min(ANS, Mainprocess(U));
    if (U < N) ANS = min(ANS, Mainprocess(U + 1));
    if (U < N - 1)
        ANS = min(ANS, Assistprocess(U + 2));
    cout << ANS << endl;
}