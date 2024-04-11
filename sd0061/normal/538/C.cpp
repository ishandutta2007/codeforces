#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m ;
pair<int , int> a[N];

void work() {
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i < m ; ++ i)
        scanf("%d%d" , &a[i].first , &a[i].second);
    sort(a , a + m);
    int res = max(a[0].second + a[0].first - 1 , a[m - 1].second + (n - a[m - 1].first));
    for (int i = 1 ; i < m ; ++ i) {
        int dh = abs(a[i].second - a[i - 1].second);
        int dx = a[i].first - a[i - 1].first;
        if (dh > dx) {
            puts("IMPOSSIBLE");
            return;
        }
        dx -= dh + 1;
        res = max(res , max(a[i].second , a[i - 1].second) + (dx + 1) / 2);
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}