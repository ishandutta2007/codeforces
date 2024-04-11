#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
LL A , B , X;
int n , l , t , m;

LL check(int T) {
    LL sum = (A + (l - 1) * B + A + (T - 1) * B) * (T - l + 1) / 2;
    return max((sum + m - 1) / m , A + (T - 1) * B);
}

void work() {
    cin >> A >> B >> n;
    while (n --) {
        cin >> l >> t >> m;
        X = A + (l - 1) * B;
        int L = l - 1 , R = l + 2e6 , mid;
        while (L < R) {
            mid = L + R + 1 >> 1;
            if (check(mid) <= t)
                L = mid;
            else
                R = mid - 1;
        }
        if (L < l)
            printf("-1\n");
        else
            printf("%d\n" , L);
    }
}

int main() {
    work();
    return 0;
}