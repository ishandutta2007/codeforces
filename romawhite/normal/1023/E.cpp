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
const int MAX = 200007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

int n;

bool ask(int x1 , int y1, int x2, int y2)
{
    assert(x2 >= x1 && y2 >= y1 && x2 - x1 + y2 - y1 >= n - 1);
    
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    cout.flush();
    string s;
    cin >> s;
    return s == "YES";
}


int main()
{
//        freopen("in.txt", "r", stdin);
    //    freopen("out.txt" , "w", stdout);
    
    
    
    cin >> n;
    
    int x = 0;
    int y = 0;
    
    string r1 = "";
    
    while (x + y < n - 1)
    {
        if (ask(x + 1 , y , n - 1 , n - 1))
        {
            r1 += 'D';
            x ++ ;
        }
        else
        {
            r1 += 'R';
            y ++;
        }
    }
    
    x = n - 1;
    y = n - 1;
    
    string r2 = "";
    
    while (x + y > n - 1)
    {
        if (ask(0,0,x , y - 1))
        {
            r2 += 'R';
            -- y;
        }
        else
        {
            r2 += 'D';
            -- x;
        }
    }
    
    reverse(ALL(r2));
    
    string res = r1 + r2;
    
    cout << "! " << res << endl;
    cout.flush();

        
}