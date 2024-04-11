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
#include <cassert>
//#pragma comment(linker, "/MTACK:16777216")
using namespace std;
typedef long long LL;
const int N = 100005;
LL n , m , K;

void work() {
    LL i , j , x , res = 0;
    cin >> n >> m >> K;
    if (K > n - 1 + m - 1) {
        puts("-1");
        return;
    }
    for (i = 1 , x ; i <= n ; i = x + 1) {
        x = n / (n / i);
        //printf("%I64d %I64d\n" , x , n / x);
        if ((K - (x - 1) + 1) > 0)
            res = max(res , (n / x) * (m / (K - (x - 1) + 1)));
    }
    swap(n , m);
    for (i = 1 , x ; i <= n ; i = x + 1) {
        x = n / (n / i);
        //printf("%I64d %I64d\n" , x , n / x);
        if ((K - (x - 1) + 1) > 0)
            res = max(res , (n / x) * (m / (K - (x - 1) + 1)));
    }
    cout << res << endl;
}

int main()
{
    work();
    return 0;
}