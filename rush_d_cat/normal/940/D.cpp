#include <iostream>
using namespace std;
const int N = 100000+10; 
const int INF = 1e9;
int n, a[N];
char b[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    scanf("%s", b+1);
    int l = -INF, r = INF;
    for (int i = 5; i <= n; i ++) {
        if (b[i]=='1'&&b[i-1]=='0') {
            int t = -INF;
            for (int j = i-4; j <= i; j ++)
                t = max(t, a[j]);
            l = max(l, t+1);
        }
        if (b[i]=='0'&&b[i-1]=='1') {
            int t = INF;
            for (int j = i-4; j <= i; j ++)
                t = min(t, a[j]);
            r = min(r, t-1);
        }
    }
    if (l > r) l = r;
    printf("%d %d\n", l, r);

}