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
#include<complex>
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
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 300007;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;

int p1 = 1000003;
int p2 = 997;
int mod1 = 1000000007;
int mod2 = 1000002727;

Int bpow(Int a, int k, int mod)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        k /= 2;
    }
    return res;
}

set<PII> S[MAX];
int ptr[MAX];

VI g[MAX];
char s[MAX];
int c[MAX];
int A1[MAX];
int B1[MAX];
int A2[MAX];
int B2[MAX];

void dfs(int v, int p)
{
    vector<PII> A;
    FOR(i,0,g[v].size())
    {
        int to = g[v][i];
        if (to == p) continue;
        dfs(to, v);
        A.push_back(MP(S[ptr[to]].size(), to));
    }
    sort(ALL(A));
    reverse(ALL(A));

    if (A.size() == 0)
    {
        S[v].insert(MP(s[v] , s[v]));
        c[v]++;
        return;
    }

    int to = A[0].second;
    ptr[v] = ptr[to];
    A1[v] = (1LL * A1[to] * p1) % mod1;
    B1[v] = (1LL * B1[to] * p1 + s[v]) % mod1;
    A2[v] = (1LL * A2[to] * p2) % mod2;
    B2[v] = (1LL * B2[to] * p2 + s[v]) % mod2;

    int invA1 = bpow(A1[v] , mod1 - 2 , mod1);
    int invA2 = bpow(A2[v] , mod2 - 2 , mod2);

    PII val = MP( 1LL * (s[v] - B1[v] + mod1) * invA1 % mod1 , 1LL * (s[v] - B2[v] + mod2) * invA2 % mod2 );
    S[ptr[v]].insert(val);

    FOR(i,1,A.size())
    {
        int to = A[i].second;
        for(set<PII>::iterator it  = S[ptr[to]].begin(); it != S[ptr[to]].end(); ++it)
        {
            int val1 = it->first;
            int val2 = it->second;
            val1 = (1LL * A1[to] * val1 + B1[to]) % mod1;
            val2 = (1LL * A2[to] * val2 + B2[to]) % mod2;
            val1 = (1LL * p1 * val1 + s[v]) % mod1;
            val2 = (1LL * p2 * val2 + s[v]) % mod2;

            PII val = MP( 1LL * (val1 - B1[v] + mod1) * invA1 % mod1 , 1LL * (val2 - B2[v] + mod2) * invA2 % mod2 );
            S[ptr[v]].insert(val);
        }
    }


    c[v] += S[ptr[v]].size();

}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &c[i]);
    }

    scanf("%s" , s);

    FOR(i,0,n - 1)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    FOR(i,0,n)
    {
        ptr[i] = i;
        A1[i] = 1;
        B1[i] = 0;
        A2[i] = 1;
        B2[i] = 0;
    }

    dfs(0, -1);

    int M = -1;
    int cnt = 0;
    FOR(i,0,n)
    {
        if (c[i] > M)
        {
            cnt = 0;
            M = c[i];
        }
        if (M == c[i]) ++cnt;
    }
    cout << M << endl;
    cout << cnt << endl;
    return 0;
}