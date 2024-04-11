#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 2000005;
int n , A , B;
int cnt[M];
LL sum[M];

int main() {
    int mx = 0;
    scanf("%d%d%d" , &n , &A , &B);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ cnt[x];
        sum[x] += x;
        mx = max(mx , x);
    }
    for (int i = 1 ; i < M ; ++ i) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    LL res = 1LL << 60;
    int dd = A / B + 1;
    for (int d = 2 ; d < M / 2 ; ++ d) {
        LL s = 0;
        for (int k = d ;  ; k += d) {
            // [k - d + 1 , k]
            // B (k - x) <= y => x >= k - y / B;
            int L = k - d + 1 , R = k , m = k - dd;
            m = max(L - 1 , min(m , R));
            s += (LL)A * (cnt[m] - cnt[L - 1]);
            s += ((LL)k * (cnt[R] - cnt[m]) - (sum[R] - sum[m])) * B;
            if (R > mx) break;
        }
        //cout << d << ' ' << s << endl;
        res = min(res , s);
    }
    cout << res << endl;
}