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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m;
pair<int , int> a[N + N];

void work() {
    int i , x , y , p = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        a[p ++] = make_pair(x , 0);
    }
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d",&x);
        a[p ++] = make_pair(x , 1);
    }
    sort(a , a + p);
    pair<int , int> ans(3 * (n - m) , 3 * n);
    x = y = 0;
    for (i = 0 ; i < p ; ++ i) {
        if (a[i].second == 0) ++ x;
        if (a[i].second == 1) ++ y;
        if (a[i].first != a[i + 1].first)
            ans = max(ans , make_pair(3 * (n - x) + 2 * x - 3 * (m - y) - 2 * y , 3 * (n - x) + 2 * x));
    }
    printf("%d:%d\n" , ans.second , ans.second - ans.first);
}

int main() {
    work();
    return 0;
}