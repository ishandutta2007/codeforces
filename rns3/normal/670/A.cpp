#include <bits/stdc++.h>
using namespace std;

int calc(int a){
    int x = a / 7, y = a % 7;
    if(y <= 5) return 2 * x;
    if(y == 6) return 2 * x + 1;
}

int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    printf("%d ", calc(n));
    if(n <= 2) printf("%d\n",n);
    else printf("%d\n", calc(n-2) + 2);
}