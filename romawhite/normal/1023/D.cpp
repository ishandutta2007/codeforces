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

int a[MAX];

int p[MAX];

int t[4 * MAX];

void build(int v, int l, int r)
{
    if (l == r)
    {
        t[v] = a[l];
        return ;
    }
    
    int m = (l + r) / 2;
    build(2 * v +1 , l , m);
    build(2 * v + 2 , m + 1 , r);
    t[v] = min(t[2 * v + 1] , t[2 * v + 2]);
}

int Min(int v,int l,int r, int L, int R)
{
    if (L > R) return INF;
    if (L == l && R == r)
    {
        return t[v];
    }
    
    int m = (l + r) / 2;
    return min(Min(2 * v + 1 , l, m, L, min(R , m)) , Min(2 * v + 2 , m + 1 , r , max(L , m + 1) , R));
}



int main()
{
//        freopen("in.txt", "r", stdin);
    //    freopen("out.txt" , "w", stdout);
    
    int n , q;
    cin >> n >> q;
    
    bool okQ = 0;
    bool ok0 = 0;
    
    
    FOR(i,0,n)
    {
        cin >> a[i];
        
        if (a[i] == q) okQ = 1;
        if (a[i] == 0) ok0 = 1;
        
    }

    if (!okQ && !ok0)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    if (!okQ)
    {
        FOR(i,0,n)
        {
            if (a[i] == 0)
            {
                a[i] = q;
                break;
            }
        }
    }
    
    FOR(i,1,n)
    {
        if (a[i] == 0 && a[i - 1] != 0) a[i] = a[i - 1];
    }
    
    RFOR(i,n - 1, 0)
    {
        if (a[i] == 0 && a[i + 1] != 0) a[i] = a[i + 1];
    }
    
    FILL(p, -1);
    
    build(0,0,n - 1);
    
    FOR(i,0,n)
    {
        if (p[a[i]] == -1) p[a[i]] = i;
        
        if (Min(0,0,n - 1 , p[a[i]] , i) < a[i])
        {
            cout << "NO" << endl;
            return 0;
        }
        
    }
    
    cout << "YES" << endl;
    FOR(i,0,n)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

        
}