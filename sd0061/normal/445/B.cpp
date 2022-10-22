#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 105;
int n , m , f[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        f[i] = i;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        f[getf(x)] = getf(y);
    }
    int res = n;
    for (i = 1 ; i <= n ; ++ i)
        if (getf(i) == i)
            -- res;
    cout << (1LL << res) << endl;
}

int main()
{
    work();
    return 0;
}