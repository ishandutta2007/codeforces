#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
const double PI=acos(-1.0);

typedef long long Int;
typedef long long LL;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;

const int INF = 1000 * 1000 * 1000;
const LL LINF = INF * (LL) INF;


const int MAX = 2007;
const int MAX1 = 2007;
const int MAX2 = 24000000;
const int LEN = 21;
const int MOD = 998244353;


int main()
{
//    freopen("in.txt", "r", stdin);
    //    ios::sync_with_stdio(false); cin.tie(0);
    
    int n , m;
    cin >> n >> m;
    VI A(n);
    FOR(i,0,n)
    {
        scanf("%d" , &A[i]);
    }
    
    VI B;
    
    FOR(i,0,m)
    {
        int x1 , x2 , y;
        scanf("%d%d%d" , &x1 , &x2 , &y);
        
        if (x1 == 1)
        {
            B.push_back(x2);
        }
    }
    
    sort(ALL(A));
    sort(ALL(B));
    A.push_back(INF);
    
    int res = INF;
    
    FOR(i,0,SZ(A))
    {
        int cur = i;
        
        int id = lower_bound(ALL(B) , A[i]) - B.begin();
        
        
        cur += SZ(B) - id;
        
        res = min(res , cur);
    }
    
    
    cout << res << endl;
    
    
    
    
    
    
    return 0;
}