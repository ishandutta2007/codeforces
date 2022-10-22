#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , a[N];
char str[N];

int main() {
    int i , x , ans = 0;
    scanf("%d%d%s" , &n , &m , str + 1);
    if (m > n / 2)
        m = n - m + 1;
    for (i = 1 ; i <= (n + 1) / 2 ; ++ i) {
        x = abs(str[i] - str[n - i + 1]);
        a[i] = min(x , 26 - x);
        ans += a[i];
    }
    int L = n , R = 0;
    for (i = 1 ; i <= (n + 1) / 2 ; ++ i) {
        if (a[i]) {
            L = min(L , i);
            R = max(R , i);
        }
    }
    if (L != n) {
        ans += R - L + min(abs(m - L) , abs(R - m));
    }
    cout << ans << endl;
    return 0;
}