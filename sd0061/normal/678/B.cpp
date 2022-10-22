#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int isleap(int y) {
    if (y % 100 == 0) {
        return y % 400 == 0;
    }
    return y % 4 == 0;
}

int main() {
    int n;
    cin >> n;
    int w = 1;
    for (int i = 2016 ; i > 1000 ; -- i) {
        if (isleap(i)) {
            w -= 366 % 7;
        } else {
            w -= 365 % 7;
        }
        w += 7 , w %= 7;
    }
    for (int i = 1001 ; i <= n ; ++ i) {
        w += isleap(i) + 365;
        w %= 7;
    }
    int p = w;
    int q = isleap(n);
    int j = n + 1;
    while (1) {
        w += isleap(j) + 365;
        w %= 7;
        if (w == p && isleap(j) == q) {
            printf("%d\n" , j);
            break;
        }
        ++ j;
    }

}