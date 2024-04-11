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

struct Data
{
    int lmin, lminidx, lmax, lmaxidx;
    int rmin, rminidx, rmax, rmaxidx;
    int omin, ominlidx, ominridx;
    int omax, omaxlidx, omaxridx;
    int rgsum;
    void init_As(int idx, int v)
    {
        lmin = lmax = rmin = rmax = omin = omax = rgsum = v;
        lminidx = lmaxidx = rminidx = rmaxidx = idx;
        ominlidx = ominridx = omaxlidx = omaxridx = idx;
    }
    void rev()
    {
        swap(lminidx, lmaxidx); swap(lmin, lmax); lmin = -lmin; lmax = -lmax;
        swap(rminidx, rmaxidx); swap(rmin, rmax); rmin = -rmin; rmax = -rmax;
        swap(ominlidx, omaxlidx); swap(ominridx, omaxridx);
        swap(omin, omax); omin = -omin; omax = -omax;
        rgsum = -rgsum;
    }
    void disp()
    {
        /*
        printf("L: i %d(%d) a %d(%d)\n", lmin, lminidx, lmax, lmaxidx);
        printf("R: i %d(%d) a %d(%d)\n", rmin, rminidx, rmax, rmaxidx);
        printf("O: i %d(%d,%d) a %d(%d,%d)\n", omin, ominlidx, ominridx, omax, omaxlidx, omaxridx);
        printf("RGS %d\n", rgsum);
        */
    }
};

Data operator + (Data lhs, Data rhs)
{
    Data ret;
    if (lhs.lmin <= lhs.rgsum + rhs.lmin)
        {
            ret.lmin = lhs.lmin;
            ret.lminidx = lhs.lminidx;
        }
    else
        {
            ret.lmin = lhs.rgsum + rhs.lmin;
            ret.lminidx = rhs.lminidx;
        }
    if (lhs.lmax >= lhs.rgsum + rhs.lmax)
        {
            ret.lmax = lhs.lmax;
            ret.lmaxidx = lhs.lmaxidx;
        }
    else
        {
            ret.lmax = lhs.rgsum + rhs.lmax;
            ret.lmaxidx = rhs.lmaxidx;
        }
    if (rhs.rmin <= rhs.rgsum + lhs.rmin)
        {
            ret.rmin = rhs.rmin;
            ret.rminidx = rhs.rminidx;
        }
    else
        {
            ret.rmin = rhs.rgsum + lhs.rmin;
            ret.rminidx = lhs.rminidx;
        }
    if (rhs.rmax >= rhs.rgsum + lhs.rmax)
        {
            ret.rmax = rhs.rmax;
            ret.rmaxidx = rhs.rmaxidx;
        }
    else
        {
            ret.rmax = rhs.rgsum + lhs.rmax;
            ret.rmaxidx = lhs.rmaxidx;
        }
    if (lhs.rmin + rhs.lmin < min(lhs.omin, rhs.omin))
        {
            ret.omin = lhs.rmin + rhs.lmin;
            ret.ominlidx = lhs.rminidx;
            ret.ominridx = rhs.lminidx;
        }
    else
        if (lhs.omin <= rhs.omin)
            {
                ret.omin = lhs.omin;
                ret.ominlidx = lhs.ominlidx;
                ret.ominridx = lhs.ominridx;
            }
        else
            {
                ret.omin = rhs.omin;
                ret.ominlidx = rhs.ominlidx;
                ret.ominridx = rhs.ominridx;
            }
    if (lhs.rmax + rhs.lmax > max(lhs.omax, rhs.omax))
        {
            ret.omax = lhs.rmax + rhs.lmax;
            ret.omaxlidx = lhs.rmaxidx;
            ret.omaxridx = rhs.lmaxidx;
        }
    else
        if (lhs.omax >= rhs.omax)
            {
                ret.omax = lhs.omax;
                ret.omaxlidx = lhs.omaxlidx;
                ret.omaxridx = lhs.omaxridx;
            }
        else
            {
                ret.omax = rhs.omax;
                ret.omaxlidx = rhs.omaxlidx;
                ret.omaxridx = rhs.omaxridx;
            }
    ret.rgsum = lhs.rgsum + rhs.rgsum;
    return ret;
}

struct SEG
{
    SEG* s[2];
    bool inv;
    Data data;
    SEG()
    {
        inv = false;
        s[0] = s[1] = NULL;
    }
    Data idata()
    {
        if (!inv) return data;
        Data ret = data;
        ret.rev();
        return ret;     
    }
};

SEG* emp(int* A, int L, int R)
{
    SEG* ret = new SEG;
    if (L == R)
        ret->data.init_As(L, A[L]);
    else
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(A, L, Mid);
            ret->s[1] = emp(A, Mid + 1, R);
            ret->data = ret->s[0]->idata() + ret->s[1]->idata();
        }
    ret->data.disp();
    return ret;
}

void modify(SEG* cur, int L, int R, int B, int v)
{
    if (cur->inv) v = -v;
    if (L == R)
        cur->data.init_As(L, v);
    else
        {
            int Mid = (L + R) / 2;
            if (B <= Mid)
                modify(cur->s[0], L, Mid, B, v);
            else
                modify(cur->s[1], Mid + 1, R, B, v);
            cur->data = cur->s[0]->idata() + cur->s[1]->idata();
        }
}

void inverse(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        {
            cur->inv ^= 1;
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) inverse(cur->s[0], L, Mid, l, r);
    if (l >  Mid) inverse(cur->s[1], Mid + 1, R, l, r);
    if ((l <= Mid) && (r > Mid))
        {
            inverse(cur->s[0], L, Mid, l, Mid);
            inverse(cur->s[1], Mid + 1, R, Mid + 1, r);
        }
    cur->data = cur->s[0]->idata() + cur->s[1]->idata();
}

Data QRG(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return cur->idata();
    int Mid = (L + R) / 2;
    Data ret;
    if (r <= Mid) ret = QRG(cur->s[0], L, Mid, l, r);
    if (l >  Mid) ret = QRG(cur->s[1], Mid + 1, R, l, r);
    if ((l <= Mid) && (r > Mid))
        ret = QRG(cur->s[0], L, Mid, l, Mid) + QRG(cur->s[1], Mid + 1, R, Mid + 1, r);
    if (cur->inv) ret.rev();
    return ret;
}

const int MAXN = 100010;

int N, M, A[MAXN];
SEG* seg;

int solve(int l, int r, int k)
{
    if (k == 0) return 0;
    Data A = QRG(seg, 1, N, l, r);
    A.disp();
    if (A.omax < 0) return 0;
    inverse(seg, 1, N, A.omaxlidx, A.omaxridx);
    int ret = A.omax + solve(l, r, k - 1);
    inverse(seg, 1, N, A.omaxlidx, A.omaxridx);
    return ret;
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    seg = emp(A, 1, N);
    scanf("%d", &M);
    fortodo(i, 1, M)
        {
            int Orz, Xu, Yin, Zhan;
            scanf("%d", &Orz);
            if (Orz == 0)
                {
                    scanf("%d%d", &Xu, &Yin);
                    modify(seg, 1, N, Xu, Yin);
                }
            else
                {
                    scanf("%d%d%d", &Xu, &Yin, &Zhan);
                    printf("%d\n", solve(Xu, Yin, Zhan));
                }
        }
}