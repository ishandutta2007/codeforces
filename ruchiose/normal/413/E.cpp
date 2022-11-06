#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int Inf = 0x3FFFFFFF;

inline void upd(int& a, int b)
{
    a = min(a, b);
}

inline bool has(int a, int b)
{
    return ((a & b) == b);
}

struct Cnx
{
    int D[2][2];
    Cnx() {}
    Cnx(int id)
    {
        int i, j, k;
        D[0][0] = (has(id, 5)) ? 1 : Inf;
        D[0][1] = ((has(id, 13)) || (has(id, 11))) ? 2 : Inf;
        D[1][0] = ((has(id, 7)) || (has(id, 14))) ? 2 : Inf;
        D[1][1] = (has(id, 10)) ? 1 : Inf;
    }
    Cnx operator +(Cnx snd)
    {
        Cnx ret;
        int i, j, k;
        fortodo(i, 0, 1)
            fortodo(j, 0, 1)
                {
                    ret.D[i][j] = Inf;
                    fortodo(k, 0, 1)
                        upd(ret.D[i][j], D[i][k] + snd.D[k][j]);
                }
        return ret;
    }
};

struct SEG
{
    SEG* s[2];
    Cnx Link;
    SEG()
    {
        s[0] = s[1] = NULL;
    }
};

int N, M, i, j, k, u, v;
int blk[200010];
char S[2][200010];
int Si[2][200010];

void emp(SEG* &cur, int L, int R)
{
    cur = new SEG;
    if (L == R)
        cur->Link = Cnx(blk[L]);
    else
        {
            int Mid = (L + R) / 2;
            emp(cur->s[0], L, Mid);
            emp(cur->s[1], Mid + 1, R);
            cur->Link = cur->s[0]->Link + cur->s[1]->Link;
        }
};

Cnx query(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return cur->Link;
    int Mid = (L + R) / 2;
    if (r <= Mid)
        return query(cur->s[0], L, Mid, l, r);
    if (l > Mid)
        return query(cur->s[1], Mid + 1, R, l, r);
    return query(cur->s[0], L, Mid, l, Mid) + query(cur->s[1], Mid + 1, R, Mid + 1, r);
}

SEG* root;

int main()
{
    scanf("%d%d%s%s", &N, &M, S[0] + 1, S[1] + 1);
    if (N == 1)
        {
            int i, u, v;
            fortodo(i, 1, M)
                {
                    scanf("%d%d", &u, &v);
                    if (u == v)
                        printf("0\n");
                    else
                        printf("1\n");
                }
            return 0;
        }
    fortodo(i, 0, 1)
        fortodo(j, 1, N)
            Si[i][j] = (S[i][j] == 'X') ? 0 : 1;
    fortodo(i, 1, N - 1)
        {
            blk[i] = 0;
            fortodo(j, 0, 1)
                fortodo(k, 0, 1)
                    blk[i] += Si[j][i + k] << (j + k * 2);
        }   
    emp(root, 1, N - 1);
    fortodo(i, 1, M)
        {
            scanf("%d%d", &u, &v);
            u--; v--;
            if (u == v)
                printf("0\n");
            else
                if ((u % N) == (v % N))
                    printf("1\n");
                else
                    {
                        if ((u % N) > (v % N)) swap(u, v);
                        Cnx b = query(root, 1, N - 1, (u % N) + 1, v % N);
                        if (b.D[u / N][v / N] == Inf)
                            printf("-1\n");
                        else
                            printf("%d\n", b.D[u / N][v / N]);
                    }
        }
}