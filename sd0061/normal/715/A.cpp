#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;

    LL x = 2;

    for (int i = 1 ; i <= n ; ++ i) {
        printf("%lld\n" , (LL)i * (i + 1) * (i + 1) - x / i);
        x = (LL)i * (i + 1);
    }

}