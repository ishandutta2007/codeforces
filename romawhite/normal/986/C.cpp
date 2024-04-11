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
#include <assert.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979


typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000000000;
const int BASE = 1000000000;
const double EPS = 1e-7;
const int MAX = 1000007;

bool U[1 << 23];
int a[1 << 23];
int n;
bool G[1 << 22];

void dfs(int v)
{
    U[v] = 1;
    //cout << v << endl;
    if (v < (1 << n))
    {
        int to = (1 << n) - 1 - v + (1 << n);
        if (!U[to])
            dfs(to);
    }
    else
    {
        int mask = v - (1 << n);
        
        if (!U[mask] && G[mask])
        {
            dfs(mask);
        }
        
        FOR(i,0,n)
        {
            if (mask & (1 << i))
            {
                int to = (v - (1 << i));
                if (!U[to])
                    dfs(to);
            }
        }
        
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    
    
    int m;
    cin >> n >> m;
    
    FOR(i,0,m)
    {
        scanf("%d" , &a[i]);
        G[a[i]] = 1;
    }
    
    int res = 0;
    
    FOR(i,0,m)
    {
        if (!U[a[i]])
        {
            ++ res;
            dfs(a[i]);
            //cout << "---" << endl;
        }
    }
    
    cout << res << endl;
    
    
    

    return 0;
}