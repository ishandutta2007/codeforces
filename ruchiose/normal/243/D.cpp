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

#include<vector>

int N, Vx, Vy;
int A[1010][1010];

vector<int> S;

struct SEG
{
    SEG* s[2];
    int Mask, Min;
    SEG()
    {
        Mask = Min = 0;
        s[0] = s[1] = NULL;
    }
    int _Min()
    {
        return max(Mask, Min);
    }
};

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    if (L < R)
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
        }
    return ret;
}

void Att(SEG* cur, int L, int R, int l, int r, int v)
{
    if ((L == l) && (R == r))
        {
            cur->Mask = max(cur->Mask, v);
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) Att(cur->s[0], L, Mid, l, r, v);
    if (l >  Mid) Att(cur->s[1], Mid + 1, R, l, r, v);
    if ((l <= Mid) && (r > Mid))
        {
            Att(cur->s[0], L, Mid, l, Mid, v);
            Att(cur->s[1], Mid + 1, R, Mid + 1, r, v);
        }
    cur->Min = min(cur->s[0]->_Min(), cur->s[1]->_Min());
}

int Qry(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r)) return cur->_Min();
    int Mid = (L + R) / 2;
    if (r <= Mid) return max(cur->Mask, Qry(cur->s[0], L, Mid, l, r));
    if (l >  Mid) return max(cur->Mask, Qry(cur->s[1], Mid + 1, R, l, r));
    return max(cur->Mask, min(Qry(cur->s[0], L, Mid, l, Mid), Qry(cur->s[1], Mid + 1, R, Mid + 1, r)));
}

SEG* seg;

int main()
{
    scanf("%d%d%d", &N, &Vx, &Vy);
    int i, j;
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            scanf("%d", &A[i][j]);
    if (Vx < 0)
        {
            Vx *= -1;
            for (int ia = 1, ib = N; ia < ib; ia++, ib--)
                fortodo(j, 1, N)
                    swap(A[ia][j], A[ib][j]);
        }
    if (Vy < 0)
        {
            Vy *= -1;
            fortodo(i, 1, N)
                for (int ja = 1, jb = N; ja < jb; ja++, jb--)
                    swap(A[i][ja], A[i][jb]);
        }
    S.clear();
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            {
                S.push_back(i * Vy - (j + 1) * Vx);
                S.push_back((i + 1) * Vy - j * Vx);
            }
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    seg = emp(1, S.size());
    i64 ans = 0;
    fortodo(i, 1, N)
        fortodo(j, 1, N)
            {
                int s = upper_bound(S.begin(), S.end(), i * Vy - (j + 1) * Vx) - S.begin();
                int e = lower_bound(S.begin(), S.end(), (i + 1) * Vy - j * Vx) - S.begin();
                int low = Qry(seg, 1, S.size(), s, e);
                ans += max(0, A[i][j] - low);
                Att(seg, 1, S.size(), s, e, A[i][j]); 
            }
    cout << ans << endl;
}