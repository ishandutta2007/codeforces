// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int N, K, S[MAXN];
vector<int> EV[MAXN];

struct SEG
{
    SEG *s[2];
    bool flip;
    int cnt[2];
    SEG()
    {
        s[0] = s[1] = NULL;
        flip = false;
        cnt[0] = cnt[1] = 0;
    }
    int Count(int x)
    {
        return cnt[x ^ flip];
    }
};

SEG* emp(int L, int R)
{
    SEG* ret = new SEG;
    ret->cnt[0] = R - L + 1;
    if (L != R)
        {
            int Mid = (L + R) / 2;
            ret->s[0] = emp(L, Mid);
            ret->s[1] = emp(Mid + 1, R);
        }
    return ret;
}

void rev(SEG* cur, int L, int R, int l, int r)
{
    if ((L == l) && (R == r))
        {
            cur->flip ^= true;
            return;
        }
    int Mid = (L + R) / 2;
    if (r <= Mid) rev(cur->s[0], L, Mid, l, r);
    if (l >  Mid) rev(cur->s[1], Mid + 1, R, l, r);
    if ((l <= Mid) && (r > Mid))
        {
            rev(cur->s[0], L, Mid, l, Mid);
            rev(cur->s[1], Mid + 1, R, Mid + 1, r);
        }
    cur->cnt[0] = cur->s[0]->Count(0) + cur->s[1]->Count(0);
    cur->cnt[1] = cur->s[0]->Count(1) + cur->s[1]->Count(1);
}

int count(SEG* cur, int L, int R, int l, int r, int c)
{
    if ((L == l) && (R == r))
        return cur->Count(c);
    int Mid = (L + R) / 2;
    if (r <= Mid) return count(cur->s[0], L, Mid, l, r, c ^ cur->flip);
    if (l >  Mid) return count(cur->s[1], Mid + 1, R, l, r, c ^ cur->flip);
    return count(cur->s[0], L, Mid, l, Mid, c ^ cur->flip) + count(cur->s[1], Mid + 1, R, Mid + 1, r, c ^ cur->flip);
}

int main()
{
    scanf("%d%d", &N, &K);
    int i;
    fortodo(i, 1, N) scanf("%d", &S[i]);
    sort(S + 1, S + N + 1);
    fortodo(i, 1, N + 1) EV[i].clear();
    fortodo(i, 1, K)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (lower_bound(S + 1, S + N + 1, u) != upper_bound(S + 1, S + N + 1, v))
                {
                    int a = lower_bound(S + 1, S + N + 1, u) - S, b = upper_bound(S + 1, S + N + 1, v) - S;
                    EV[a].push_back(a); EV[a].push_back(b);
                    EV[b].push_back(a); EV[b].push_back(b);
                }
        }
    i64 sumTrim = 1;
    sumTrim *= N; sumTrim *= N - 1; sumTrim *= N - 2;
    sumTrim /= 6;
    i64 sumComb = 0;
    SEG* root = emp(1, N);
    fortodo(i, 1, N)
        {
            sort(EV[i].begin(), EV[i].end());
            int E = EV[i].size();
            for (int e = 0; e < E; e += 2)
                if (EV[i][e] != EV[i][e + 1])
                    rev(root, 1, N, EV[i][e], EV[i][e + 1] - 1);
            int deg = 0;
            if (i != 1) deg += count(root, 1, N, 1, i - 1, 0);
            if (i != N) deg += count(root, 1, N, i + 1, N, 1);
            sumComb += deg * (deg - 1LL) / 2;
        }
    cout << (sumTrim - sumComb) << endl;
}