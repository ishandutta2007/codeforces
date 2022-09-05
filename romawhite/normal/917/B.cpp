

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
#include <bitset>
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
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 107;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

vector<PII> G[MAX];
int M[2][MAX][MAX][30];

bool f(int player , int a, int b , int t)
{
    if (M[player][a][b][t] != -1) return M[player][a][b][t];
    
    int & res = M[player][a][b][t];
    res = 0;
    
    if (player == 0)
    {
        FOR(i,0,SZ(G[a]))
        {
            if (G[a][i].second < t) continue;
            if (f(player ^ 1 , G[a][i].first ,  b , G[a][i].second) == 0)
            {
                res = 1;
                return res;
            }
        }
    }
    else
    {
        FOR(i,0,SZ(G[b]))
        {
            if (G[b][i].second < t) continue;
            if (f(player ^ 1 , a, G[b][i].first , G[b][i].second) == 0)
            {
                res = 1;
                return res;
            }
        }
    }
    return res;
    
    
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    
    int n , m;
    cin >> n >> m;
    
    FOR(i,0,m)
    {
        int a , b;
        char c;
        cin >> a >> b >> c;
        --a;--b;
        G[a].push_back(MP(b , c - 'a'));
    }
    
    FILL(M , -1);
    
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if (f(0,i,j,0))
            {
                cout << 'A';
            }
            else
            {
                cout << 'B';
            }
            
        }
        cout << endl;
        
    }
    
    return 0;
}