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
#include <complex.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const Int INF2 = Int(INF) * 5000;
const Int INF3 = Int(INF) * INF;
const int MAX = 57;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

int p = 1000003;

int A[4][MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n , k;
    cin >> n >> k;
    
    FOR(i,0,4)
    {
        FOR(j,0,n)
        {
            cin >> A[i][j];
        }
    }
    
    vector<pair<int, PII> > RES;
    
    if (k == 2 * n)
    {
        bool ok = false;
        FOR(i,0,n)
        {
            if (A[0][i] == A[1][i] && A[0][i] != 0)
            {
                RES.push_back(MP(A[0][i] , MP(1 , i + 1)));
                ok = true;
                A[0][i] = A[1][i] = 0;
            }
        }
        FOR(i,0,n)
        {
            if (A[2][i] == A[3][i] && A[2][i] != 0)
            {
                RES.push_back(MP(A[2][i] , MP(4 , i + 1)));
                
                ok = true;
                A[2][i] = A[3][i] = 0;
            }
        }
        
        if (!ok)
        {
            cout << "-1" << endl;
            return 0;
        }
        
    }
    
    while (true)
    {
        bool found = false;
        
        FOR(i,0,n)
        {
            if (A[1][i] == 0) continue;
            
            found = true;
            
            if (A[0][i] == A[1][i])
            {
                RES.push_back(MP(A[0][i] , MP(1 , i + 1)));
                A[0][i] = A[1][i] = 0;
                continue;
            }
            
            int x = 1;
            int y = i + 1;
            if (y == n)
            {
                x = 2;
                y = n - 1;
            }
            
            if (A[x][y] == 0)
            {
                RES.push_back(MP(A[1][i] , MP(x + 1 , y + 1)));
                swap(A[1][i] , A[x][y]);
            }
        }
        FOR(i,0,n)
        {
            if (A[2][i] == 0) continue;
            
            found = true;
            
            if (A[2][i] == A[3][i])
            {
                RES.push_back(MP(A[2][i] , MP(4 , i + 1)));
                A[2][i] = A[3][i] = 0;
                continue;
            }
            
            int x = 2;
            int y = i - 1;
            if (y == -1)
            {
                x = 1;
                y = 0;
            }
            
            if (A[x][y] == 0)
            {
                RES.push_back(MP(A[2][i] , MP(x + 1 , y + 1)));
                swap(A[2][i] , A[x][y]);
            }
        }
        
        if (!found) break;
    }
    
    cout << SZ(RES) << endl;
    FOR(i,0,SZ(RES))
    {
        cout << RES[i].first << ' ' << RES[i].second.first << ' ' << RES[i].second.second << endl;
    }
    
}