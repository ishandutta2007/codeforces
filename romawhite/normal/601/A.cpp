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
const int MAX = 407;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;
const int MOD = 1000000007;


int G[MAX][MAX];

int d[MAX];
int q[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n , m;
    cin >> n >> m;
    FOR(i,0,m)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        --a;--b;
        G[a][b] = G[b][a] = 1;
    }
    if (G[0][n - 1] == 1)
    {
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                G[i][j] ^= 1;
            }
        }
    }

    FOR(i,0,MAX)
    {
        d[i] = INF;
    }
    d[0] = 0;
    int L = 0;
    int R = 0;
    q[R++] = 0;
    while (L < R)
    {

        int v = q[L++];
        FOR(i,0,n)
        {
            if (G[v][i] && d[i] == INF)
            {
                d[i] = d[v] + 1;
                q[R++] = i;
            }
        }
    }
    if (d[n - 1] == INF) d[n - 1] = -1;
    cout << d[n - 1] << endl;

    return 0;
}