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
int n;

int a[1000][1000];

void dfs(int x , int y){
    int s = a[x][y] / 4;
    a[x][y] -= 4 * s;
    if (x < 300 || x > 700 || y < 300 || y > 700)
        cout << "ERROR\n";
    a[x - 1][y] += s;
    if (a[x - 1][y] >= 4)
        dfs(x - 1 , y);
    a[x + 1][y] += s;
    if (a[x + 1][y] >= 4)
        dfs(x + 1 , y);
    a[x][y - 1] += s;
    if (a[x][y - 1] >= 4)
        dfs(x , y - 1);
    a[x][y + 1] += s;
    if (a[x][y + 1] >= 4)
        dfs(x , y + 1);
}


int main()
{
    int n;
    cin >> n;
    a[500][500] = n;
    dfs(500 , 500);
    int t;
    cin >> t;
    FOR(ttt,0,t){
        int x,y;
        cin >> x >> y;
        if (abs(x) > 100 || abs(y) > 100){
            cout << 0 << endl;
            continue;
        }
        cout << a[x + 500][y + 500] << endl;
    }
    return 0;
};