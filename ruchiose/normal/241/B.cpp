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

int N, A[50010];
i64 M;

struct TRIE
{
    TRIE* s[2];
    int tot;
    vector<int> cnt;
    TRIE()
    {
        s[0] = s[1] = NULL;
        tot = 0;
        cnt.clear();
    }
    i64 With(int V)
    {
        i64 ret = 0;
        int i;
        for (i = cnt.size() - 1; i >= 0; i--)
            if ((V >> i) & 1)
                ret += (1LL << i) * (tot - cnt[i]);
            else
                ret += (1LL << i) * cnt[i];
        return ret;
    }
};

TRIE* trie = NULL;

void Att(TRIE* &cur, int lv, int V)
{
    if (cur == NULL) cur = new TRIE;
    cur->tot++;
    if (lv >= 0)
        {
            if (V & (1 << lv))
                Att(cur->s[1], lv - 1, V ^ (1 << lv));
            else
                Att(cur->s[0], lv - 1, V);
        }
}

void Stat(TRIE* cur, int lv)
{
    if (lv == -1) return;
    cur->cnt.resize(lv + 1, 0);
    cur->cnt[lv] = (cur->s[1]) ? cur->s[1]->tot : 0;
    int i;
    if (cur->s[0]) Stat(cur->s[0], lv - 1);
    if (cur->s[1]) Stat(cur->s[1], lv - 1);
    fortodo(i, 0, lv - 1)
        {
            if (cur->s[0]) cur->cnt[i] += cur->s[0]->cnt[i];
            if (cur->s[1]) cur->cnt[i] += cur->s[1]->cnt[i];
        }
}

int Count(TRIE* cur, int lv, int V, int thres)
{
    if (cur == NULL) return 0;
    if (thres == 0) return cur->tot;
    if (thres & (1 << lv)) return Count(cur->s[(~V >> lv) & 1], lv - 1, V, thres ^ (1 << lv));
    int ret = Count(cur->s[(V >> lv) & 1], lv - 1, V, thres);
    if (cur->s[(~V >> lv) & 1]) ret += cur->s[(~V >> lv) & 1]->tot;
    return ret;
}

i64 Allcount(int thres)
{
    i64 ret = 0;
    int i;
    fortodo(i, 1, N) ret += Count(trie, 29, A[i], thres);
    //printf("Allcount(%d) = %I64d\n", thres, ret);
    return ret;
}

i64 Sum(TRIE* cur, int lv, int V, int thres)
{
    if (cur == NULL) return 0;
    if (thres == 0) return cur->With(V);
    int d = (V >> lv) & 1;
    i64 ret;
    if (thres & (1 << lv))
        ret = (1LL << lv) * Count(cur->s[d ^ 1], lv - 1, V, thres ^ (1 << lv)) + Sum(cur->s[d ^ 1], lv - 1, V, thres ^ (1 << lv));
    else
        {
            ret = Sum(cur->s[d], lv - 1, V, thres);
            if (cur->s[d ^ 1]) ret += cur->s[d ^ 1]->With(V) + cur->s[d ^ 1]->tot * (1LL << lv);
        }
    //printf("call Sum(%d, %d, %d, %d) = %I64d\n", &cur, lv, V, thres, ret);
    return ret;
}

i64 Allsum(int thres)
{
    i64 ret = 0;
    int i;
    fortodo(i, 1, N) ret += Sum(trie, 29, A[i], thres);
    return ret;
}

int main()
{
    cin >> N >> M; M <<= 1;
    int i;
    fortodo(i, 1, N) scanf("%d", &A[i]);
    fortodo(i, 1, N) Att(trie, 29, A[i]);
    Stat(trie, 29);
    int L = 0, R = 1 << 30;
    while (R - L > 1)
        {
            int Mid = (L + R) / 2;
            if (Allcount(Mid) >= M)
                L = Mid;
            else
                R = Mid;
        }
    cout << ((Allsum(L) - (Allcount(L) - M) * L) / 2 % (int(1e+9) + 7)) << endl;
}