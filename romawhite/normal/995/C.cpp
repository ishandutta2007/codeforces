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
const int MAX = 100007;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

Int dist(Int X,  Int Y)
{
    return X * X + Y * Y;
}
Int res[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n;
    cin >> n;
    vector<pair<int, PII> > A;
    FOR(i,0,n)
    {
        int x , y;
        cin >> x >> y;
        A.push_back(MP(i, MP(x , y)));
    }
    
    while (true)
    {
        random_shuffle(ALL(A));
        
        int X = 0;
        int Y = 0;
        
        FOR(i,0,SZ(A))
        {
            Int X1 = X + A[i].second.first;
            Int Y1 = Y + A[i].second.second;
            Int X2 = X - A[i].second.first;
            Int Y2 = Y - A[i].second.second;
            
            if (dist(X1 , Y1) < dist(X2 , Y2))
            {
                X = X1;
                Y = Y1;
                res[A[i].first] = 1;
            }
            else
            {
                X = X2;
                Y = Y2;
                res[A[i].first] = -1;
            }
            
        }
        
        if (dist(X , Y) < 1500000LL * 1500000)
        {
            FOR(i,0,n)
            {
                cout << res[i] << ' ';
            }
            cout << endl;
            return 0;
        }
        
    }
}