#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
const int Q = 1e9 + 7;
typedef long long LL;

int n , f[N];
pair<int , int> a[N];
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d%d" , &a[i].first , &a[i].second);
    sort(a , a + n);
    int res = n;
    
    for (int i = 0 ; i < n ; ++ i) {
        int j = lower_bound(a , a + n , make_pair(a[i].first - a[i].second , -1)) - a - 1;
        if (j >= 0) {
            f[i] = f[j] + 1;
        } else {
            f[i] = 1;
        }
        res = min(res , n - f[i]);
    }
    printf("%d\n" , res);
    return 0;
}