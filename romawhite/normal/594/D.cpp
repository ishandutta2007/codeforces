#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <cassert>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int bpow(Int a , int k)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        k /= 2;
    }
    return res;
}
vector<PII> L[MAX];
vector<PII> R[MAX];

Int t[4 * MAX];
Int pref[MAX];

void Set(int v , int l , int r , int pos , Int val)
{
    if (l == r)
    {
        t[v] = val;
        return;
    }
    if (t[v] != 1)
    {
        t[2 * v + 1] *= t[v];
        t[2 * v + 1] %= MOD;
        t[2 * v + 2] *= t[v];
        t[2 * v + 2] %= MOD;
        t[v] = 1;
    }
    int m = (l + r) / 2;
    if (pos <= m)
    {
        Set(2 * v + 1, l, m, pos , val);
    }
    else
    {
        Set(2 * v + 2 , m + 1 , r , pos , val);
    }
}

Int Get(int v , int l, int r, int pos)
{
    if (l == r)
    {
        return t[v];
    }
    if (t[v] != 1)
    {
        t[2 * v + 1] *= t[v];
        t[2 * v + 1] %= MOD;
        t[2 * v + 2] *= t[v];
        t[2 * v + 2] %= MOD;
        t[v] = 1;
    }
    int m = (l + r) / 2;
    if (pos <= m)
    {
        return Get(2 * v + 1, l, m, pos);
    }
    else
    {
        return Get(2 * v + 2 , m + 1 , r , pos);
    }
}

void Mult(int v, int l, int r, int L, int R, Int val)
{
    if (L > R) return;
    if (l == L && r == R)
    {
        t[v] *= val;
        t[v] %= MOD;
        return;
    }
    int m = (l + r) / 2;
    Mult(2 * v + 1 , l, m, L, min(R , m) , val);
    Mult(2 * v + 2, m + 1 , r, max(L , m + 1) , R , val);
}

map<int,int> M;

Int res[MAX];

int p[1000007];

int main()
{
    //freopen("in.txt" , "r" , stdin);

    FOR(i,0,4 * MAX)
        t[i] = 1;

    for(int i = 2; i * i < 1000007; ++i)
        if (!p[i])
            for(int j = i * i; j < 1000007; j += i)
                if (!p[j])
                    p[j] = i;
    FOR(i,0,1000007)
        if (!p[i])
            p[i] = i;

    int n;
    cin >> n;
    VI a(n);
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }
    pref[0] = a[0];
    FOR(i,1,n)
    {
        pref[i] = pref[i - 1] * a[i] % MOD;
    }

    int q;
    cin >> q;
    vector<pair<PII, int> > B;
    FOR(i,0,q)
    {
        int l , r;
        scanf("%d%d" , &l , &r);
        --l;--r;
        B.push_back(MP(MP(l, r), i) );
        res[i] = pref[r];
        if (l)
        {
            res[i] *= bpow(pref[l - 1] , MOD - 2);
            res[i] %= MOD;
        }
    }

    sort(ALL(B));
    FOR(i,0,q)
    {
        L[B[i].first.first].push_back(MP(B[i].first.second , i));
        R[B[i].first.second].push_back(MP(B[i].first.first , i));
    }

    FOR(i,0,n)
    {
        FOR(j,0,L[i].size())
        {
            //cout << L[i][j].second << " s " << 1 << endl;
            Set(0,0,q - 1 , L[i][j].second , 1LL);
        }
        int x = a[i];
        VI b;
        while (x != 1)
        {
            int pp = p[x];
            b.push_back(pp);
            while (x % pp == 0) x /= pp;
        }
        FOR(j,0,b.size())
        {
            int pp = b[j];
            int prev = -1;
            if (M.count(b[j]))
            {
                prev = M[b[j]];
            }
            int id = lower_bound(ALL(B) , MP(MP(prev , INF) , INF)) - B.begin();
            Int val = 1LL * bpow(pp, MOD - 2) * (pp - 1) % MOD;
            Mult(0,0,q - 1,id , q - 1, val);
            //cout << id << " m " << q - 1 << ' ' << val << endl;
            M[b[j]] = i;
        }
        FOR(j,0,R[i].size())
        {
            Int val = Get(0,0,q - 1 , R[i][j].second);
            //cout << R[i][j].second << " g " << endl;
            int pos = B[R[i][j].second].second;
            res[pos] *= val;
            res[pos] %= MOD;
        }
    }

    FOR(i,0,q)
    {
        printf("%I64d\n" , res[i]);
    }



    return 0;
}