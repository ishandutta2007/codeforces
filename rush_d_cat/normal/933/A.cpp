#include <iostream>
#include <cstring>
using namespace std;
const int N = 200000+10;
int n, a[N];
int c1[N], c2[N], mx[N];
int d1[N], d2[N], my[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++) {
        c1[i] = c1[i-1] + (a[i] == 1);
        c2[i] = c2[i-1] + (a[i] == 2);
    }  
    for (int i = n; i >= 1; i --) {
        d1[i] = d1[i+1] + (a[i] == 1);
        d2[i] = d2[i+1] + (a[i] == 2);
    }

    for (int i = 1; i <= n; i ++) {
        mx[i] = max(mx[i-1], c1[i]-c2[i]);
    }
    for (int i = n; i >= 1; i --) {
        my[i] = max(my[i+1], d2[i]-d1[i]);
    }
    /*
    [p1, p2]
    s2-s1-my[i] = ?
    */

    if (c1[n] == n || c1[n] == 0) {
        return !printf("%d\n", n);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) if (a[i] == 1) {
        int p1 = c1[i-1], p2 = c2[i-1];
        int s1 = d1[i+1], s2 = d2[i+1];
        int ds2 = max(0, mx[i-1] + p2 - p1);
        int dp1 = max(0, my[i+1] + s1 - s2);
        ans = max(ans, p1+dp1+s2+ds2+1);
    }    
    printf("%d\n", ans);
}