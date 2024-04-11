

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

vector<int> l[MAX];
vector<int> r[MAX];
int m[MAX];
int ml[MAX];
int mr[MAX];
char s[10];

vector<int> res;
bool ok = 1;

int n , c;

int t[4 * MAX];
void upd(int v , int l, int r, int pos , int val)
{
    if (l == r)
    {
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) upd(2 * v + 1, l , m, pos, val);
    else upd(2 * v + 2, m + 1, r, pos, val);
    t[v] = max(t[2 * v + 1] , t[2 * v + 2]);
}

int Max(int v, int l, int r, int L, int R)
{
    if (L > R) return -1;
    if (l == L && r == R)
    {
        return t[v];
    }
    int m = (l + r) / 2;
    return max( Max(2 * v + 1 , l , m , L, min(R , m)) , Max(2 * v + 2, m + 1, r , max(m + 1, L) , R));
}

void solve(int L, int R)
{
    if (L > R) return;
    if (l[L].size() == 0)
    {
        res.push_back(L);
        solve(L + 1, R);
        return;
    }
    if (r[L].size() == 0)
    {
        solve(L + 1, R);
        res.push_back(L);
        return;
    }
    int rr = ml[L];
    int ll = mr[L];
    //cout << n << endl;
    int pos = Max(0,0,n - 1, L + 1, rr);
    //cout << L + 1 << ' ' << rr - 1 << endl;
    rr = pos + 1;
   // cout << L << ' ' << R << ' ' << rr << ' ' << ll << endl;
    if (rr > ll)
    {
        ok = 0;
        return;
    }
    solve(L + 1, rr - 1);
    res.push_back(L);
    solve(rr, R);
}



int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n >> c;

    FOR(i,0,n)
    {
        m[i] = i;
        ml[i] = i;
        mr[i] = INF;
    }

    FOR(i,0,c)
    {
        int a, b;
        scanf("%d%d%s", &a , &b, &s);
        --a;--b;
        m[a] = max(m[a] , b);
        if (s[0] == 'L')
        {
            l[a].push_back(b);
            ml[a] = max(ml[a] , b);
        }
        if (s[0] == 'R')
        {
            r[a].push_back(b);
            mr[a] = min(mr[a] , b);
        }
        if (a >= b)
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    RFOR(i,n,0)
    {
        int v = Max(0,0,n - 1,i, m[i]);
        v = max(v , m[i]);
        upd(0,0,n - 1, i, v);
    }


    solve(0, n - 1);
    if (!ok)
    {
           printf("IMPOSSIBLE\n");
            return 0;
    }
    FOR(i,0,res.size())
    {
        printf("%d " , res[i] + 1);
    }
    cout << endl;

    return 0;
}