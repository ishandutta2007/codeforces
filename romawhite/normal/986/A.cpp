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
const int MAX = 100007;

int a[MAX];
VI G[MAX];

int Q[MAX];
int d[MAX];

int D[MAX][107];

int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n , m , k , s;
    cin >> n >> m >> k >> s;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        --a[i];
    }
    FOR(i,0,m)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    FOR(i,0,k)
    {
        FOR(j,0,n)
        {
            d[j] = INF;
        }
        int L = 0;
        int R = 0;
        FOR(j,0,n)
        {
            if (a[j] == i)
            {
                Q[R ++] = j;
                d[j] = 0;
            }
        }
        
        while (L < R)
        {
            int v = Q[L++];
            FOR(j,0,SZ(G[v]))
            {
                int to = G[v][j];
                if (d[to] != INF) continue;
                d[to] = d[v] + 1;
                Q[R ++] = to;
            }
        }
        
        FOR(j,0,n)
        {
            D[j][i] = d[j];
        }
    }
    
    FOR(i,0,n)
    {
        sort(D[i] , D[i] + k);
        
        int res = 0;
        FOR(j,0,s)
        {
            res += D[i][j];
        }
        printf("%d " , res);
    }
    cout << endl;
    
    
    
    

    return 0;
}