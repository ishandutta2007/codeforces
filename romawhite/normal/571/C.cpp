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
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int BASE = 1000000000;
const int MOD = 1000000007;

int p[MAX];

vector<pair<int,int> > X[MAX];

int res[MAX];
bool used[MAX];

vector<pair<int,int> > g[MAX];

int find_set(int v)
{
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

bool union_sets(int a, int b)
{
    //cout << a << ' ' << b << endl;
    a = find_set(a);
    b = find_set(b);
    //cout << a << ' ' << b << endl;
    if (a == b) return 0;
    if (rand() % 2) swap(a , b);
    p[b] = a;
    return 1;
}

void G(int v, int x)
{
    if (X[x][0].first == v)
    {
        res[x] = X[x][0].second;
    }
    else
    {
        res[x] = X[x][1].second;
    }
}

void dfs(int v)
{
    //cout << v << endl;
    used[v] = 1;
    FOR(i,0,g[v].size())
    {
        int to = g[v][i].first;
        if (used[to]) continue;
        G(to, g[v][i].second);
        dfs(to);
    }
}



int main()
{   
    //freopen("in.txt","r",stdin);

    int n , m;
    cin >> m >> n;
    
    FOR(i,0,m)
    {
        p[i] = i;
    }
    
    FOR(i,0,m)
    {
        int l;
        scanf("%d" , &l);
        FOR(j,0,l)
        {
            int x;
            scanf("%d" , &x);
            if (x > 0)
            {
                --x;
                X[x].push_back(MP(i,1));
            }
            else
            {
                x *= -1;
                --x;
                X[x].push_back(MP(i, 0));
            }
        }
    }

    FOR(i,0,n)
    {
        if (X[i].size() == 0) continue;
        if (X[i].size() == 1)
        {
            res[i] = X[i][0].second;
            //G(X[i][0].first , i);
            if (!used[X[i][0].first])
            {
                dfs(X[i][0].first);
            }
        }
        if (X[i].size() == 2)
        {
            if (X[i][0].second == X[i][1].second)
            {
                res[i] = X[i][0].second;
                if (!used[X[i][0].first])
                {
                    dfs(X[i][0].first);
                }
                if (!used[X[i][1].first])
                {
                    dfs(X[i][1].first);
                }
            }
            else
            {
                //cout << X[i][0].first << ' ' << X[i][1].first << endl;
                
                if (used[X[i][0].first])
                {
                    res[i] = X[i][1].second;
                    if (!used[X[i][1].first])
                    {
                        dfs(X[i][1].first);
                    }
                    union_sets(X[i][0].first , X[i][1].first);
                }
                else
                {
                    if (used[X[i][1].first])
                    {
                        res[i] = X[i][0].second;
                        if (!used[X[i][0].first])
                        {
                            dfs(X[i][0].first);
                        }
                        union_sets(X[i][0].first , X[i][1].first);
                    }
                    else
                    if (!union_sets(X[i][0].first , X[i][1].first))
                    {
                        res[i] = X[i][0].second;
                        if (!used[X[i][0].first])
                        {
                            dfs(X[i][0].first);
                        }
                    }
                    else
                    {
                        g[X[i][0].first].push_back(MP(X[i][1].first , i));
                        g[X[i][1].first].push_back(MP(X[i][0].first , i));
                    }
                }
            }
        }
    }
    
    bool ok = 1;
    FOR(i,0,m)
    {
        ok &= used[i];
    }
    if (!ok) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        FOR(i,0,n)
        {
            printf("%d" , res[i]);
        }
        cout << endl;
    }
    
}