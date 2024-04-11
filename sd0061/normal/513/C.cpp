#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

double res , delta;
int n , k;
int l[N] , r[N];

void dfs(int i , double p , int b , int c) {
    if (c > 1) return;
    if (i == n) {
        if (b + c <= 1)
            return;
        delta += p;
        return;
    }
    int x = k;
    if (x >= l[i] && x <= r[i]) {
        dfs(i + 1, p / (r[i] - l[i] + 1),  b + 1, c);
    }
    if (x > l[i]) {
        dfs(i + 1, p / (r[i] - l[i] + 1) * (min(r[i] + 1, x) - l[i]), b, c);
    }
    if (x < r[i]) {
        dfs(i + 1, p / (r[i] - l[i] + 1) * (r[i] - max(l[i] - 1, x)), b, c + 1);
    }
}

void work() {
    int i;
    cin >> n;
    for (i = 0 ; i < n ; ++ i)
        cin >> l[i] >> r[i];
    for (k = 1 ; k <= 10000 ; ++ k) {
        delta = 0;
        dfs(0 , 1.0 , 0 , 0);
        res += delta * k;
    }
    printf("%.15f\n" , res);
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}