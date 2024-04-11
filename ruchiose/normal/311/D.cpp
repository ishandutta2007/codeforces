#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 95542721ll;
const i64 Cyc = 48;
const int MAXN = 100010;

i64 Cubic(i64 x)
{
    return (x * x % MOD) * x % MOD;
}

int N, Q, i, j;
i64 A[MAXN][Cyc];

struct SEG
{
    SEG *s[2];
    int Rotation;
    i64 V[Cyc];
    SEG()
    {
        s[0] = s[1] = NULL;
        Rotation = 0;
    }
    inline i64 v(int x)
    {
        return V[(x + Rotation) % Cyc];
    }
};

void emp(SEG* &cur, int L, int R)
{
    cur = new SEG;
    if (L == R)
        {
            int i;
            fortodo(i, 0, Cyc - 1) cur->V[i] = A[L][i];
            return;
        }
    int Mid = (L + R) / 2;
    emp(cur->s[0], L, Mid);
    emp(cur->s[1], Mid + 1, R);
    int i;
    fortodo(i, 0, Cyc - 1)
        cur->V[i] = (cur->s[0]->v(i) + cur->s[1]->v(i)) % MOD;
}

i64 qry(SEG* cur, int L, int R, int l, int r, int rho)
{
    if ((L == l) && (R == r))
        return cur->v(rho);
    int Mid = (L + R) / 2;
    if (r <= Mid)
        return qry(cur->s[0], L, Mid, l, r, (rho + cur->Rotation) % Cyc);
    if (l > Mid)
        return qry(cur->s[1], Mid + 1, R, l, r, (rho + cur->Rotation) % Cyc);
    return (qry(cur->s[0], L, Mid, l, Mid, (rho + cur->Rotation) % Cyc)
         + qry(cur->s[1], Mid + 1, R, Mid + 1, r, (rho + cur->Rotation) % Cyc)) % MOD;
}

void modify(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        {
            cur->Rotation++;
            cur->Rotation %= Cyc;
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) modify(cur->s[0], L, Mid, l, r);
    if (l >  Mid) modify(cur->s[1], Mid + 1, R, l, r);
    if ((l <= Mid) && (r > Mid))
        {
            modify(cur->s[0], L, Mid, l, Mid);
            modify(cur->s[1], Mid + 1, R, Mid + 1, r);
        }
    int i;
    fortodo(i, 0, Cyc - 1)
        cur->V[i] = (cur->s[0]->v(i) + cur->s[1]->v(i)) % MOD;
}

SEG* root;

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N)
        {
            scanf("%d", &j);
            A[i][0] = j % MOD;
            fortodo(j, 1, Cyc - 1)
                A[i][j] = Cubic(A[i][j - 1]);
        }
    emp(root, 1, N);
    scanf("%d", &Q);
    fortodo(i, 1, Q)
        {
            int Opt, L, R;
            scanf("%d%d%d", &Opt, &L, &R);
            if (Opt == 1) cout << qry(root, 1, N, L, R, 0) << endl;
            if (Opt == 2) modify(root, 1, N, L, R);
        }
}