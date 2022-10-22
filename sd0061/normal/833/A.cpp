#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {
        int a , b;
        scanf("%d%d" , &a , &b);
        long long d = (long long)a * b;
        int c = max(0 , (int)pow(d , 1.0 / 3) - 5);
        while ((long long)c * c * c < d) ++ c;
        if ((long long)c * c * c != d) {
            puts("No");
        } else {
            if (a == 1 && b == 1) {
                puts("Yes");
            } else if (a % c || b % c) {
                puts("No");
            } else {
                a /= c, b /= c;
                //printf("%d %d %d\n" , a , b , c);
                puts("Yes");
            }
        }

    }
}