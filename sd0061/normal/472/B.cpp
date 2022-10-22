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
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 2505;
const int M = 200005;

int n , a[N] , k;

void work() {
    int i;
    cin >> n >> k;
    for (i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    sort(a , a + n);
    int ans = 0;
    for (i = n - 1 ; i >= 0 ; i -= k)
        ans += 2 * (a[i] - 1);
    cout << ans << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}