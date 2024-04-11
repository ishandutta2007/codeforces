#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define itr(x) x::iterator

typedef vector < int > vi;
typedef long long ll;

int n, cnt, curk;
vi x;
int a, b;
vi tree;
vi maxDiv;

void
upd(int x, int val)
{
    x += curk;
    tree[x] = val;
    int par = x / 2;
    while (par != 0)
    {
        tree[par] = min(tree[par * 2], tree[par * 2 + 1]);
        par /= 2;
    }
}

int
minSeg(int l, int r)
{
    int res = b - a + 1;
    l += curk;
    r += curk;
    while (l < r)
    {
        res = min(res, min(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r)
    {
        res = min(res, tree[l]);
    }
    return res;
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data(void)
{
#ifdef _DEBUG
    if (!(cin >> n))
    {
        return false;
    }
#else
    cin >> n;
#endif
    x.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    itr(vi) it = unique(x.begin(), x.end());
    x.resize(it - x.begin());
    cin >> a >> b;
    swap(a, b);
#ifdef _DEBUG
    return true;
#endif
}

void
calc(void)
{
    cnt = b - a + 1;
    curk = 2;
    while (curk < cnt)
    {
        curk *= 2;
    }
#ifdef _DEBUG
    cerr << "cnt = " << cnt << " curk = " << curk << endline;
#endif
    tree.assign(2 * curk + 1, cnt + 1);
    maxDiv.assign(cnt, 2);
    int cntX = sz(x);
    for (int i = 0; i < cntX; ++i)
    {
        for (int itr = (a + x[i] - 1) / x[i] * x[i] - a; itr <= b - a + 1; itr += x[i])
        {
            maxDiv[itr] = x[i];
        }
    }
#ifdef _DEBUG
    cerr << "ok" << endline;
#endif
    upd(b - a, 0);
#ifdef _DEBUG
    cerr << "ok" << endline;
#endif
    for (int i = b - a - 1; i >= 0; --i)
    {
        int l_b = i + 1;
        int r_b = min(i + maxDiv[i] - 1, cnt - 1);
        int res = minSeg(l_b, r_b) + 1;
#ifdef _DEBUG
        cerr << "min[" << i + a << "] = " << res << endline;
#endif
        upd(i, res);
    }
    cout << minSeg(0, 0) << endline;
}

int
main(void)
{
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
    input_data();
#else
    while (input_data())
    {
#endif
    calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}