#include<bits/stdc++.h>

typedef long long ll;

int inv(int a, int moder){
    int b = moder, s = 1, t = 0;
    while (b){
        int tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    if (a > 1) return -1;
    return s < 0 ? s + moder : s;
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <int> prime;
    int nn = n;
    for (int i = 2; i * i <= n; ++ i){
        if (n % i == 0){
            prime.push_back(i);
            while (n % i == 0){
                n /= i;
            }
        }
    }
    if (n > 1){
        prime.push_back(n);
    }
    n = nn;
    if (prime.size() == 1){
        puts("NO");
        return 0;
    }
    ll x = inv(prime[0], prime[1]);
    ll y = -(x * prime[0] - 1) / prime[1];
    x *= n - 1, y *= n - 1;
    if (y < 0){
        ll tmp = std::abs(y / prime[0]);
        x -= tmp * prime[1];
        y += tmp * prime[0];
    }
    while (y <= 0){
        x -= prime[1];
        y += prime[0];
    }
    if (x > 0 && y > 0){
        printf("YES\n2\n%lld %d\n%lld %d\n", x, n / prime[0], y, n / prime[1]);
    }
    else{
        puts("NO");
    }
    return 0;
}