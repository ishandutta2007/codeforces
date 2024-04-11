#include<bits/stdc++.h>
using namespace std;
int a, b, x, y, n;
int main() {
    scanf("%d", &n);
    while (n --) scanf("%d%d", &x, &y), x < 0 ? a++ : b++;
    puts(a > 1 && b > 1 ? "No" : "Yes");
    return 0;
}