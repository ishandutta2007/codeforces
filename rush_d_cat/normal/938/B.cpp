#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000+10; 
int n, a[N];
int min(int x, int y) {return x < y ? x: y;}
int main() {
    scanf("%d", &n);
    a[0] = 1, a[n+1] = 1000000;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int ans = 1e7;
    for (int i = 0; i <= n; i ++)
        ans = min(ans, max(a[i]-1, 1000000-a[i+1]));
    printf("%d\n", ans);
}