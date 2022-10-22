#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;

int n;
LL a[N] , L;

int main() {
    cin >> n >> L;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    for (int i = n ; i <= 30 ; ++ i) {
        a[i] = 1LL << 60;
    }
    n = 31;
    for (int i = 1 ; i < n ; ++ i) {
        a[i] = min(a[i] , a[i - 1] * 2);
    }
    LL res = 1LL << 60 , sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        if (L >> i & 1) {
            sum += a[i];
        }
        int v = 1 << i;
        res = min(res , (L + v - 1) / v * a[i]);
    }
    res = min(res , sum);
    sum = 0;
    for (int i = n - 1 ; i >= 0 ; -- i) {
        if (~L >> i & 1) {
            res = min(res , sum + a[i]);
        } else {
            sum += a[i];
        }
    }
    cout << res << endl;
}