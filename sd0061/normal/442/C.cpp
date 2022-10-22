#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 500005;
int n , a[N];
int s[N] , top;
void work() {
    int i , j , k , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    LL ans = 0;
    for (i = 1 ; i <= n ; ++ i) {
        while (top > 1 && s[top - 1] >= s[top] && s[top] <= a[i]) {
            ans += min(s[top - 1] , a[i]);
            -- top;
        }
        s[++ top] = a[i];
    }
    nth_element(s + 1 , s + top - 1 , s + top + 1);
    for (i = 1 ; i <= top - 2 ; ++ i)
        ans += s[i];
    cout << ans << endl;
}


int main()
{
    work();
    return 0;
}