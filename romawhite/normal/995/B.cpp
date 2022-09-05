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
const int MAX = 107;
const int MAXE = 2007000;
const int MAXV = 5000;
const int BASE = 1000000000;
const int ST = 1000000007;

const int MOD = 1000000007;

VI A[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n;
    cin >> n;
    
    FOR(i,0,2 * n)
    {
        int x;
        cin >> x;
        --x;
        A[x].push_back(i);
    }
    
    int res = 0;
    FOR(i,0,n)
    {
        res += A[i][1] - A[i][0] - 1;
    }
    
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if (A[i][0] < A[j][0] && A[j][0] < A[i][1] && A[i][1] < A[j][1])
                -- res;
        }
    }
    
    cout << res << endl;
    
    
    
    
}