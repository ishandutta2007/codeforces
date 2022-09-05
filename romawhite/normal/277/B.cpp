#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <time.h>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(LL(i)=(a);i<b;i++)
#define RFOR(i,a,b) for(int(i)=(a-1);i>=b;i--)
#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define next htrhtrhtrh
#define ALL(A) A.begin(),A.end()
#define SZ(A) A.size()
#define FILL(a,b) memset(a,b,sizeof(a))
#define CLEAR(a) memset(a,0,sizeof(a))

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;

const int MAX = 200000;
const int INF = 100000000;
const int MOD = 1000000007;
const double EPS = 1E-7;
const int IT = 10024;

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin >> n >> m;

    if (m == 3 && n > 4){
        cout << -1 << endl;
        return 0;
    }

    double R1 = 10000000.0;
    double R2 = 100000.0;

    double d = 2.0 * PI / m;

    int s = 0;
    FOR(i,0,8)
        s = 10 * s + rand() % 10;

    double st = s;
    FOR(i,0,7)
        st *= 0.1;

    for(int i = 0; i < m; ++i){
        printf("%d %d\n" , (int)(R1 * cos(st)) , (int)(R1 * sin(st)));
        st += d;
    }

    d = 2.0 * PI / (n - m);
    s = 0;
    FOR(i,0,8)
        s = 10 * s + rand() % 10;

    st = s;
    FOR(i,0,7)
        st *= 0.1;

    for(int i = 0; i < n - m; ++i){
        printf("%d %d\n" , (int)(R2 * cos(st)) , (int)(R2 * sin(st)));
        st += d;
    }
}