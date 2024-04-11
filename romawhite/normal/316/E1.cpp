//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

int F[107];
int a[107];

int main()
{
    F[0] = F[1] = 1;
    FOR(i,2,107)
        F[i] = (F[i - 1] + F[i - 2]) % INF;

    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        cin >> a[i];

    FOR(i,0,m){
        int d;
        cin >> d;
        if(d == 1){
            int x,v;
            cin >>x >> v;
            a[x - 1] = v;
        }
        if (d == 2){
            int l,r;
            cin >> l >> r;
            --l;
            LL res = 0;
            FOR(i,0,r - l){
                res += 1LL * a[i + l] * F[i];
                res %= INF;
            }
            cout << res << endl;
        }
    }
    return 0;
};