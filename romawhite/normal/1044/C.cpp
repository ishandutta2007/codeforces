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
    
    int n;
    cin >> n;
    
    VI X(n);
    VI Y(n);
    
    FOR(i,0,n)
    {
        scanf("%d%d" , &X[i] , &Y[i]);
    }
    
    int minX = INF;
    int minY = INF;
    int maxX = -INF;
    int maxY = -INF;
    
    FOR(i,0,n)
    {
        minX = min(minX , X[i]);
        maxX = max(maxX , X[i]);
        minY = min(minY , Y[i]);
        maxY = max(maxY , Y[i]);
    }
    
    int res = 0;
    
    FOR(i,0,n)
    {
        int xx = max(X[i] - minX , maxX - X[i]);
        int yy = max(Y[i] - minY , maxY - Y[i]);
        
        res = max(res , 2 * (xx + yy));
    }
    
    cout << res << ' ';
    
    FOR(i,4,n + 1)
    {
        printf("%d " , 2 * (maxX - minX) + 2 * (maxY - minY));
    }
    
    cout << endl;
    
    
    
    
    
    
    
    return 0;
}