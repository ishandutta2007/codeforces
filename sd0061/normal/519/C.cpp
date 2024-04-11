#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 205;

int n , m;
void work() {
    cin >> n >> m;
    int res = 0;
    while (1) {
        if (n >= m) {
            if (n < 2) break;
            if (m < 1) break;
            ++ res; n -= 2 , m -= 1;
        } else {
            if (m < 2) break;
            if (n < 1) break;
            ++ res; m -= 2 , n -= 1;        
        }
    }
    printf("%d\n", res);
}

int main() {
    work();
    return 0;
}