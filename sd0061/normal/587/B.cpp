#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int n , K;
LL l;
pair<int , int> a[N];
int f[N];
int main() {
    scanf("%d%lld%d" , &n , &l , &K);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = i;
    }
    sort(a , a + n);
    for (int i = 0 ; i < n ; ++ i)
        f[i] = 1;
    int res = 0;
    for (int i = 0 ; i < K ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            LL cnt = l / n + (a[j].second < l % n);
            if (cnt > i)
                res += (cnt - i) % Q * f[j] % Q;
            res %= Q;
        }
        int sum = 0;
        for (int j = 0 , k = 0 ; j < n ; ++ j) {
            while (k < n && a[k].first <= a[j].first)
                sum += f[k ++] , sum %= Q;
            f[j] = sum;
        }
    }
    printf("%d\n" , res);
    return 0;
}