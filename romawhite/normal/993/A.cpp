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

const int BASE = 1000;
const double EPS = 1e-7;
const int MAX = 17;
const int INF = 1000000000;


bool inside(int mx1, int Mx1 , int my1, int My1, int x , int y)
{
    return x >= mx1 && x <= Mx1 && y >= my1 && y <= My1;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int mx1 = INF;
    int Mx1 = - INF;
    int my1 = INF;
    int My1 = -INF;
    
    FOR(i,0,4)
    {
        int x , y;
        cin >> x >> y;
        mx1 = min(mx1 , x);
        Mx1 = max(Mx1 , x);
        my1 = min(my1 , y);
        My1 = max(My1 , y);
    }
    
    int mx2 = INF;
    int Mx2 = - INF;
    int my2 = INF;
    int My2 = -INF;
    
    FOR(i,0,4)
    {
        int x , y;
        cin >> x >> y;
        mx2 = min(mx2 , x);
        Mx2 = max(Mx2 , x);
        my2 = min(my2 , y);
        My2 = max(My2 , y);
    }

    FOR(x,mx2 , Mx2 + 1)
    {
        int d = min(x - mx2 , Mx2 - x);
        
        
        FOR(dy,-d , d + 1)
        {
            int y = (my2 + My2) / 2 + dy;
            
            if (inside(mx1 , Mx1 , my1 , My1, x , y))
            {
                cout << "YES" << endl;
                return 0;
            }
            
        }
        
    }
    
    cout << "NO" << endl;
    
    return 0;
}