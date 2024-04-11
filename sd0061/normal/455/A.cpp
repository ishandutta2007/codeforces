#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long LL;

const int N = 100005;
int n , cnt[N];
LL f[N][2];
void work() {
    int i , j , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        ++ cnt[x];
    }
    memset(f , 0xC0 , sizeof(f));
    f[1][0] = 0 , f[1][1] = (LL)cnt[1];
    LL res = f[1][1];
    for (i = 2 ; i <= 100000 ; ++ i) {
        f[i][0] = max(f[i - 1][0] , f[i - 1][1]);
        f[i][1] = f[i - 1][0] + (LL) cnt[i] * i;
        res = max(res , f[i][1]);
    }
    cout << res << endl;
}


int main()
{
 //   freopen("~input.txt" , "r" , stdin);
//    while (~scanf("%d%d",&n,&K))
        work();
    return 0;
}