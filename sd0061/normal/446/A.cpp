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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N] , L[N] , R[N];
void work() {
    int i , j , ans = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; ++ i)
        if (i == 1 || a[i] > a[i - 1])
            L[i] = L[i - 1] + 1;
        else
            L[i] = 1;
    for (i = n ; i > 0 ; -- i)
        if (i == n || a[i] < a[i + 1])
            R[i] = R[i + 1] + 1;
        else
            R[i] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        if (i == 1 || i == n || a[i - 1] + 2 <= a[i + 1])
            ans = max(ans , L[i - 1] + R[i + 1] + 1);
        ans = max(ans , R[i + 1] + 1);
        ans = max(ans , L[i - 1] + 1);
        ans = max(ans , R[i]);
    }
    printf("%d\n" , ans);
}


int main(){
        work();
    return 0;
}