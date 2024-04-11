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
const int MAX = 100007;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int mn[MAX];
int mx[MAX];
int a[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }
    mx[0] = a[0];
    FOR(i,1,n)
    {
        mx[i] = max(mx[i - 1] , a[i]);
    }
    mn[n - 1] = a[n - 1];
    RFOR(i,n - 1 , 0)
    {
        mn[i] = min(mn[i + 1] , a[i]);
    }
    int res = 1;
    FOR(i,0,n - 1)
    {
        if (mn[i + 1] >= mx[i]) ++res;
    }
    cout << res << endl;



    return 0;
}