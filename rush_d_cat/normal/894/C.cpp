#include <iostream>
#include <set>

using namespace std;
int n, g, a[1002], vis[1000000+10];

int gcd(int x, int y) {
    return y==0?x:gcd(y,x%y);
}

int main() {    
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        vis[a[i]] = 1; g = gcd(g, a[i]);
    }

    if (!vis[g]) {printf("-1\n"); return 0;}

    printf("%d\n", 2*n);
    for (int i=1;i<=2*n;i++)
        printf("%d ", i%2?a[(i+1)/2]:g);
}