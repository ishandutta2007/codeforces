#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 55;
const int Q = 1e9 + 7;

int n;
LL K , fib[N];

void work() {
    fib[0] = fib[1] = 1;
    cin >> n >> K;
    for (int i = 2 ; i <= n ; ++ i)
        fib[i] = fib[i - 1] + fib[i - 2];
    int x = 1 , y = n;
    while (x <= n) {
        if (K <= fib[n - x]) {
            printf("%d\n" , x);            
            ++ x;            
        } else {
            K -= fib[n - x];
            printf("%d\n" , x + 1);
            printf("%d\n" , x);
            x += 2;
        }
    }
}

int main() {
    work();    
    return 0;
}