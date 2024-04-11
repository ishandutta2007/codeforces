#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    scanf("%d" , &n);
    puts("YES");
    for (int i = 0 ; i < n ; ++ i) {
        int x1 , x2 , y1 , y2;
        scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);
        int c = (x1 & 1) << 1 | (y1 & 1);
        printf("%d\n" , c + 1);
    }
}