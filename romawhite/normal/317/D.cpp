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
    if (x < 10 || x > 990 || y < 10 || y > 990)
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

bool used[100007];

int f[] = {1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};

int main()
{
    cin >> n;
    FILL(used , 0);
    int xr = 1;
    LL S = (int)sqrt(1.0 * n);

    int rest = n - S; 

    for(int i = 2; i * i <= n; ++i)
        if (!used[i]){
        LL j = i;
        int t = 0;
        while (j <= n){
            j *= i;
            if (j < 100000)
                used[j] = 1;
            ++t;
            if (j <= n && j > S)
                rest--;
        }
        xr ^= f[t - 1];
    }
    if (rest % 2 == 1)
        xr ^= 1;
    if (xr == 0)
        cout << "Petya\n";
    else cout << "Vasya\n";

    return 0;
};