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

const int MOD = 1000000007;



int main()
{
    LL x , y , m;
    cin >> x >> y >> m;
    if (x >= m || y >= m){
        cout << 0 << endl;
        return 0;
    }
    if (x <= 0 && y <= 0){
        cout << -1 << endl;
        return 0;
    }
    if (x > y)
        swap(x , y);

    LL res = 0;

    if (x < 0){
        res += abs(x) / y;
        x += y * (abs(x) / y);
    }

    while(x < m && y < m){
        if (x < y) x = x + y;
        else y = x + y;
        ++res;
    }

    cout << res << endl;

    return 0;
};