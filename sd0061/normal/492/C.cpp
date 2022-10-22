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
const int N = 100005;
int n , r , avg;
pair<int , int> a[N];

void work() {
    int i ;
    LL cnt = 0 , sum , res = 0;
    scanf("%d%d%d",&n,&r,&avg);
    sum = (LL) n * avg;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].second, &a[i].first);
        cnt += a[i].second;
    }
    sort(a , a + n);
    for (i = 0 ; i < n ; ++ i) {
        LL x = max(0LL , min(sum - cnt , (LL)r - a[i].second));
        res += x * a[i].first;
        cnt += x;
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}