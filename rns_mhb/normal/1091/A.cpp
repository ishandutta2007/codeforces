#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a ++, c --;
    b = min(b, min(a, c));
    printf("%d\n", 3 * b);
}