#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
int n , Q , a[N] , A , B , sum , s2;
unordered_set<int> H;
int nn , nnn;
int inverse(int x) {
    return x == 1 ? 1 : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}
bool check(int d) {
    int x = (sum - (LL)B * d % Q + Q) % Q;
    x = (LL)x * inverse(A) % Q; int t = x;
    // sum(x + kd)^2 = nx^2 + 2 * nn * d * x + nnn * d * d
    int w = ((LL)n * x % Q * x + 2LL * nn * d % Q * x + (LL)nnn * d % Q * d) % Q;
    if (w != s2) return 0;
    for (int j = 0 ; j < n ; ++ j) {
        if (!H.count(x)) return 0;
        x += d; if (x >= Q) x -= Q;
    }
    printf("%d %d\n" , t , d);
    exit(0); return 1;
}
int main() {
    scanf("%d%d" , &Q , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    nn = ((LL)n * (n - 1) / 2) % Q;
    nnn = ((LL)(n - 1) * n * (n + n - 1) / 6) % Q;
    A = n % Q , B = ((LL)n * (n - 1) / 2) % Q;
    if (n == 1) {
        printf("%d 0\n" , a[0]);
        return 0;
    }
    if (n == Q) {
        printf("0 1\n");
        return 0;
    }
    if (n > Q) {
        puts("-1");
        return 0;
    }
    for (int i = 0 ; i < n ; ++ i) {
        sum = (sum + a[i]) % Q;
        s2 = (s2 + (LL)a[i] * a[i] % Q) % Q;
        H.insert(a[i]);
    }
    for (int i = 1 ; i < n ; ++ i) {
        check((a[i] - a[0] + Q) % Q);
    }

    printf("-1\n");
}