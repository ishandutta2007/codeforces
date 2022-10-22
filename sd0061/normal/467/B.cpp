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
int n , m , k;
int a[N];

void work() {
    cin >> n >> m >> k;
    for (int i = 0 ; i <= m ; ++ i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0 ; i < m ; ++ i) {
        int x = a[i] ^ a[m];
        if (__builtin_popcount(x) <= k)
            ++ ans;
    }
    cout << ans << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}