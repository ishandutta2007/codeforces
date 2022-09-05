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
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000;
const LL LINF = INF * (LL) INF;


const int MAX = 200007;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int MOD = 998244353;

PII t[4 * MAX];
int p[4 * MAX];

PII Merge(PII a , PII b)
{
    if (a.first < b.first)
        return a;
    if (a.first > b.first)
        return b;
    return MP(a.first , a.second + b.second);
}

void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = MP(0, 1);
        return;
    }
    
    int m = (l + r) / 2;
    
    build(2 * v + 1 , l , m);
    build(2 * v + 2 , m + 1 , r);
    
    t[v] = Merge(t[2 * v + 1] , t[2 * v + 2]);
}

void push(int v)
{
    
    
    t[2 * v + 1].first += p[v];
    p[2 * v + 1] += p[v];
    
    t[2 * v + 2].first += p[v];
    p[2 * v + 2] += p[v];
    
    p[v] = 0;
}

void Upd(int v, int l, int r, int L, int R, int delta)
{
    if (L > R) return;
    
    
    if (l == L && r == R)
    {
        t[v].first += delta;
        p[v] += delta;
        return;
    }
    
    push(v);
    
    int m = (l + r) / 2;
    Upd(2 * v + 1 , l , m , L , min(R , m), delta);
    Upd(2 * v + 2 , m + 1 , r , max(L, m + 1) , R, delta);
    
    t[v] = Merge(t[2 * v + 1] , t[2 * v + 2]);
}

int tin[MAX];
int tout[MAX];

int timer = 0;

VI G[MAX];

int up[MAX][20];

void dfs(int v, int p)
{
    tin[v] = timer ++;
    
    up[v][0] = p;
    FOR(i,1,20)
    {
        up[v][i] = up[ up[v][i - 1] ] [i - 1];
    }
    
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i];
        if (to == p)
            continue;
        dfs(to, v);
    }
    
    
    tout[v] = timer;
}

bool upper(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}


int go_up(int u, int v)
{
    RFOR(i,20,0)
    {
        if (!upper(up[v][i] , u))
            v = up[v][i];
    }
    return v;
}

set<PII> S;
int n , q;

void add(int v, int delta)
{
    Upd(0, 0, n - 1, tin[v], tout[v] - 1, delta);
}




int main()
{
//    freopen("in.txt", "r", stdin);
    //    ios::sync_with_stdio(false); cin.tie(0);

    
    cin >> n >> q;
    
    FOR(i,0,n - 1)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        
        G[a].push_back(b);
        G[b].push_back(a);
        
    }
    
    
    dfs(0, 0);
    
    build(0,0,n - 1);
    
    
    FOR(i,0,q)
    {
        int u , v;
        scanf("%d%d", &u, &v);
        
        --u;--v;
        
        if (u > v) swap(u, v);
        
        int coef = 1;
        
        
        
        
        if (S.find(MP(u, v)) != S.end())
        {
            S.erase(MP(u, v));
            coef *= -1;
        }
        else
        {
            S.insert(MP(u, v));
        }
            
        if (upper(v, u)) swap(u, v);
        
        if (upper(u, v))
        {
            add(go_up(u, v), coef);
            add(v, -coef);
        }
        else
        {
            add(0, coef);
            add(u, -coef);
            add(v, -coef);
        }
        
        
        int res = 0;
        if (t[0].first == 0)
        {
            res = t[0].second;
        }
        
        printf("%d\n" , res);
    }
    
    
    
    
    return 0;
}