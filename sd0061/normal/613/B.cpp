#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , cf , cm , A;
pair<int , int> a[N];
LL m , s[N];
int ans[N] , H[N] , b[N];
LL check(int w , int h) {
    int j = upper_bound(b , b + w , h) - b;
    LL res = (LL)j * h - s[j];
    return res;
}

void work() {    
    scanf("%d%d%d%d%lld" , &n ,&A , &cf , &cm , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = i;
        ans[i] = a[i].first;
    }
    sort(a , a + n);
    for (int i = 0 ; i < n ; ++ i) {
        s[i + 1] = s[i] + a[i].first;
        b[i] = a[i].first;
    }
    LL res = -1LL << 60;
    int p = -1;
    for (int i = 0 ; i <= n ; ++ i) {      
        int l = a[0].first , r = A , mid;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (check(n - i , mid) <= m)
                l = mid;
            else
                r = mid - 1;
        }
        H[i] = l;
        LL cnt = (LL)l * cm + (LL)i * cf;
        if (cnt > res) {
            res = cnt;
            p = i;
        }
        if (i == n) break;
        int delta = A - a[n - i - 1].first;
        if (m < delta) break;
        m -= delta;
    }
    cout << res << endl;
    for (int i = 0 ; i < n - p ; ++ i)
        ans[a[i].second] = max(H[p] , ans[a[i].second]);
    for (int i = n - p ; i < n ; ++ i)
        ans[a[i].second] = A;
    for (int i = 0 ; i < n ; ++ i)
        printf("%d%c" , ans[i] , " \n"[i + 1 == n]);
}

int main() {    
    work();
    return 0;
}