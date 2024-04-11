#include<bits/stdc++.h>
using namespace std;
int a, b, c, ans;
int main() {
    scanf("%d %d %d", &a, &b, &c);
    for (ans = 1; ans < 1e6; ans ++, a = a * 10 % b)
        if (a * 10 / b == c) return printf("%d", ans), 0;
    puts("-1");
    return 0;
}