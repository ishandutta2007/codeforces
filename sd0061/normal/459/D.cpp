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
const int N = 1000005;
map<int , int> hash;
int n , a[N] , c[N];
int L[N] , R[N];

void work() {
    int i , j , x , y;
    LL ans = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&a[i]);
        L[i] = ++ hash[a[i]];
    }
    hash.clear();
    for (i = n - 1 ; i >= 0 ; -- i) {
        R[i] = ++ hash[a[i]];
    }
    for (i = 0 ; i < n ; ++ i) {
        for (j = R[i] + 1 ; j <= n ; j += j & -j)
            ans += c[j];
        for (j = L[i] ; j > 0 ; j -= j & -j)
            ++ c[j];
    }
    cout << ans << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}