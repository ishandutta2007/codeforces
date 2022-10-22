#include <bits/stdc++.h>
using namespace std;
const int N = 200005;


int main() {
    int x = 20000 , y = 0;
    int n; cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        int t;
        char str[10];
        scanf("%d%s" , &t , str);
        if (*str == 'E') {
            if (y == 0 || y == 20000) {
                puts("NO");
                return 0;
            }
            //x = ((x - t % 40000) + 40000) % 40000;
        }
        if (*str == 'W') {
            if (y == 0 || y == 20000) {
                puts("NO");
                return 0;
            }
            //x = ((x + t % 40000) + 40000) % 40000;
        }
        if (*str == 'N') {
            if (y < t) {
                puts("NO");
                return 0;
            }
            y -= t;
        }
        if (*str == 'S') {
            if (y + t > 20000) {
                puts("NO");
                return 0;
            }
            y += t;
        }
    }
    if (y != 0) puts("NO"); else
    puts("YES");
}