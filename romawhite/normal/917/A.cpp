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
const int MAX = 5007;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

short O[MAX][MAX];
short OF[MAX][MAX];
short C[MAX][MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    
    string s;
    cin >> s;
    
    int n = SZ(s);
    
    FOR(i,0,n)
    {
        int bal = 0;
        int mn = 0;
        FOR(j,i,n)
        {
            if (s[j] == '(' || s[j] == '?')
                bal ++;
            else
                bal --;
            mn = min(mn , bal);
            O[i][j] = mn;
            OF[i][j] = bal;
        }
    }
    FOR(i,0,n)
    {
        int bal = 0;
        int mn = 0;
        FOR(j,i,n)
        {
            if (s[j] == '(')
                bal ++;
            else
                bal --;
            mn = min(mn , bal);
            C[i][j] = mn;
        }
    }
    
    int res = 0;
    FOR(i,0,n)
    {
        VI a;
        int open = 0;
        int closed = 0;
        
        FOR(j,i,n)
        {
            if (s[j] == '(') ++ open;
            if (s[j] == ')') ++ closed;
            if (s[j] == '?') a.push_back(j);
            
            if (j % 2 != i % 2)
            {
                int len = j - i + 1;
                if (open > len / 2 || closed > len / 2) continue;
                int t = len / 2 - open;
                int id;
                if (t == 0)
                {
                    if (C[i][j] == 0)
                    {
                        ++ res;
                    }
                }
                else
                {
                    id = a[t - 1] + 1;
                    
                    
                    if (O[i][id - 1] < 0) continue;
                    if (OF[i][id - 1] + C[id][j] < 0) continue;
                    
                    ++ res;
                }
                
            }
            
        }
        
        
        
    }
    
    cout << res << endl;
    
    
    
    
    return 0;
}