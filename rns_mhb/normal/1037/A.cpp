#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", 32 - __builtin_clz(n));
}