#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 1000005

int c , d , n , m , k;

void work()
{
    int ans = 1 << 30 , i;
    cin >> c >> d >> n >> m >> k;
    for (i = 0 ; n * i + k <= n * m ; ++ i) {
        int j = n * m - k - n * i;
        ans = min(ans , c * i + d * j);
    }
    ans = min(ans , i * c);
    cout << ans << endl;
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}