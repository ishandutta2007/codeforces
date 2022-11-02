#include<bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    d = min(a, min(b / 2, c / 4));
    printf("%d\n", 7 * d);

    return 0;
}