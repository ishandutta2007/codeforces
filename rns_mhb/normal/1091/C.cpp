#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    set <long long> s;
    for(int i = 1; i * i <= n; i ++) if(n % i == 0) s.insert(1ll * (n + 2) * i - n);
    for(int i = 1; i * i < n; i ++) if(n % i == 0) s.insert(1ll * (n + 2) * n / i - n);
    for(auto x : s) printf("%I64d ", x >> 1);
    puts("");
}