#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, K, D, i, j, A[200010];
int ans, st, ed, hd;
map<int,int> ls;

struct SEG
{
    int Offset, Min;
    SEG* S[2];
    SEG()
    {
        Offset = 0;
        S[0] = S[1] = NULL;
    }
};

void SEG_Destroy(SEG* &p)
{
    if (p == NULL) return;
    SEG_Destroy(p->S[0]);
    SEG_Destroy(p->S[1]);
    delete p;
    p = NULL;
    return;
}

#define rm(Cur) (Cur->Min + Cur->Offset)
void SEG_Recalc(SEG* Cur)
{
    Cur->Min = min(rm(Cur->S[0]), rm(Cur->S[1]));
}

void SEG_Inherit(SEG* Cur)
{
    if (Cur->Offset == 0) return;
    Cur->Min += Cur->Offset;
    if (Cur->S[0]) Cur->S[0]->Offset += Cur->Offset;
    if (Cur->S[1]) Cur->S[1]->Offset += Cur->Offset;
    Cur->Offset = 0;
}

void SEG_Offset(SEG* Cur, int L, int R, int l, int r, int Delta)
{
    SEG_Inherit(Cur);
    if ((L == l) && (R == r))
        {
            Cur->Offset += Delta;
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) SEG_Offset(Cur->S[0], L, Mid, l, r, Delta);
    if (l >  Mid) SEG_Offset(Cur->S[1], Mid + 1, R, l, r, Delta);
    if ((l <= Mid) && (r > Mid))
        {
            SEG_Offset(Cur->S[0], L, Mid, l, Mid, Delta);
            SEG_Offset(Cur->S[1], Mid + 1, R, Mid + 1, r, Delta);
        }
    SEG_Recalc(Cur);
}

int SEG_FLMSOE(SEG* Cur, int L, int R, int l, int r, int threshold)
// Find Left-most Smaller or equal
{
    SEG_Inherit(Cur);
    if (rm(Cur) > threshold) return -1;
    if (L == R) return L;
    int Mid = (L + R) / 2;
    if (r <= Mid) return SEG_FLMSOE(Cur->S[0], L, Mid, l, r, threshold);
    if (l > Mid) return SEG_FLMSOE(Cur->S[1], Mid + 1, R, l, r, threshold);
    int p = SEG_FLMSOE(Cur->S[0], L, Mid, l, Mid, threshold);
    if (p == -1)
        p = SEG_FLMSOE(Cur->S[1], Mid + 1, R, Mid + 1, r, threshold);
    return p;
}

void SEG_New(SEG* &Cur, int L, int R)
{
    Cur = new SEG;
    Cur->Min = L;
    if (L == R) return;
    int Mid = (L + R) / 2;
    SEG_New(Cur->S[0], L, Mid);
    SEG_New(Cur->S[1], Mid + 1, R);
}

int Maxpre[200010], Minpre[200010];
// Maxpre[i] + 1  i  maxinum, min 

void Process(int* A, int Len, int plus)
{
    SEG* G;
    SEG_New(G, 1, Len);
    int i, Left = 1;
    fortodo(i, 1, Len) A[i] /= D;
    fortodo(i, 1, Len) Maxpre[i] = Minpre[i] = i - 1;
    ls.clear();
    fortodo(i, 1, Len)
        {
            Left = max(Left, ls[A[i]] + 1);
            ls[A[i]] = i;
            while ((Maxpre[i]) && (A[Maxpre[i]] < A[i]))
                {
                    SEG_Offset(G, 1, Len, Maxpre[Maxpre[i]] + 1, Maxpre[i], A[i] - A[Maxpre[i]]);
                    Maxpre[i] = Maxpre[Maxpre[i]];
                }
            while ((Minpre[i]) && (A[Minpre[i]] > A[i]))
                {
                    SEG_Offset(G, 1, Len, Minpre[Minpre[i]] + 1, Minpre[i], A[Minpre[i]] - A[i]);
                    Minpre[i] = Minpre[Minpre[i]];
                }
            int p = SEG_FLMSOE(G, 1, Len, Left, i, K + i);
            if (i - p + 1 > ans)
                {
                    ans = i - p + 1;
                    st = p + plus;
                    ed = i + plus;
                }
        }
    SEG_Destroy(G);
}

int main()
{
    scanf("%d%d%d", &N, &K, &D);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) A[i] += 1000000000;
    ans = st = ed = 1;
    if (D == 0)
        {
            hd = 1;
            fortodo(i, 2, N)
                {
                    if (A[i] != A[hd]) hd = i;
                    if (i - hd + 1 > ans)
                        {
                            ans = i - hd + 1;
                            st = hd;
                            ed = i;
                        }
                }
            printf("%d %d\n", st, ed);
            return 0;
        }
    hd = 1;
    fortodo(i, 2, N + 1)
        if ((A[i] % D != A[hd] % D) || (i == N + 1))
            {
                Process(A + hd - 1, i - hd, hd - 1);
                hd = i;
            }
    printf("%d %d\n", st, ed);
}