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

int a[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("electricity.in", "r" , stdin);
    //freopen("electricity.out" , "w" , stdout);

    int n;
    cin >> n;
    int s = 0;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        s += a[i];
    }
    bool q = 0;
    if (s % n) q = 1;
    s /= n;
    int res1 = 0;
    FOR(i,0,n)
    {
        if (a[i] < s)
            res1 += s - a[i];
    }
    int res2 = 0;
    s += q;
    FOR(i,0,n)
    {
        if (a[i] > s)
            res2 += a[i] - s;
    }

    cout << max(res1 , res2) << endl;

    return 0;
}