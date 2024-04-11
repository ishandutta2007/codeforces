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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define For(i, a, b) for(int i=(a);i<(b);i++)
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
const int MAX = 100007;
const int MAX2 = 200000;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 2000;

vector<int> g[MAX];

int root = -1;

int dfs(int v, int p)
{

    if (root >= 0)
    {
        return 0;
    }

    vector<int> a;
    FOR(i,0,g[v].size())
    {
        if (g[v][i] != p)
        {
            int c = dfs(g[v][i], v);
            
            if (root == -1)
            {
                root = v;
                return 0;
            }
            
            a.push_back(c);
        }   
    }
    sort(ALL(a));
    reverse(ALL(a));
    
    if (a.size() == 0) return 0;
    
    if (a[0] == 1)
    {
        return 2;
    }
    
    if (a.size() == 1) return a[0];
    
    if (a[0] == 0)
    {
        if (a.size() == 2) return 1;
        else return 2;
    }
    
    
    
    if (a[0] == 2)
    {
        if (a[1] <= 1)
        {
            return 2;
        }
        if (a.size() == 2 || a[2] <= 1) return 3;
        return 4;
    }
    
    if (a[0] == 3)
    {
        if (a[1] == 0 && a.size() <= 3)
        {
            return 3;
        }
        return 4;
    }
    return 4;
}

int main()
{   
    //freopen("in.txt","r",stdin);
    
    int n;
    cin >> n;
    
    FOR(i,0,n - 1)
    {
        int a , b;
        scanf("%d %d" , &a , &b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int r = dfs(0,-1);
    
    if (root != -1)
    {
        int v = root;
        root = -2;
        r = dfs(v , -1);
    }
    
    if (r < 4)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}