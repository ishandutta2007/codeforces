#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , t , r;
int a[N] , cnt[N];
bool f[N];

void work() {
    int i , j , k , res = 0;
    cin >> n >> t >> r;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i] , a[i] += 400;
    sort(a , a + n);
    for (i = 0 ; i < n ; ++ i) {
        int x = a[i];
        while (cnt[x] < r) {
            for (j = x ; j > x - t ; -- j) {
                if (f[j]) continue;
                for (k = j ; k <= j + t - 1 ; ++ k)
                    ++ cnt[k];
                ++ res , f[j] = 1;
                break;
            }
            if (j <= x - t) {
                puts("-1");
                return;
            }
        }
    }
    cout << res << endl;
}
int main()
{
    work();
    return 0;
}