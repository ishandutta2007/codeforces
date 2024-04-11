#include <iostream>
using namespace std;
typedef long long LL;
int n, a, b, c, ans = 0;
int main() {
    scanf("%d %d %d", &n, &a, &b);
    for(int i=1;i<=n;i++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            if(a > 0) {
                a --;
            } else if(b > 0) {
                b --;
                c ++;
            } else if(c > 0) {
                c --;
            } else {
                ans ++;
            }
        } 

        if(t == 2) {
            if(b > 0) {
                b --;
            } else {
                ans += 2;
            }
        }
    }
    printf("%d\n", ans);
}