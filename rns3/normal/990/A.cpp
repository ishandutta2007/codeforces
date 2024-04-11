#include <bits/stdc++.h>

using namespace std;



long long n, m;

int a, b;



int main() {

    //freopen("r.in", "r", stdin);

    scanf("%I64d %I64d %d %d", &n, &m, &a, &b);

    long long tmp = (n / m) * m;

    long long ans = min((n - tmp) * b, (tmp + m - n) * a);

    printf("%I64d\n", ans);



    return 0;

}