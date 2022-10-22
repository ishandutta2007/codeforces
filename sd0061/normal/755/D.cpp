#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int c[N] , n , K;

int add(int x) {
    for (int i = x ; i <= n ; i += i & -i) {
        c[i] ++;
    }
}
int sum(int x) {
    int res = 0;
    for (int i = x ; i > 0 ; i -= i & -i) {
        res += c[i];
    }
    return res;
}
int get(int x , int y) {
    if (y >= x) {
        return sum(y) - sum(x - 1);
    } else {
        return sum(n) - sum(x - 1) + sum(y);
    }
}

int main() {
    cin >> n >> K;
    long long res = 1 , x = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        int y = x + K;
        if (y > n) y -= n;
        if (K < n - K) {
            res += get(x + 1 , y - 1) + 1;
        } else {
            res += get(1 , n) - get(x , y) + 1;
        }
        add(x);
        add(y);
        x = y;
        printf("%lld%c" , res , " \n"[i == n]);
    }
}