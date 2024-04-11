#include <iostream>
using namespace std;
int n, m, l, r, x;
int a[10000+2];
int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d %d %d", &l, &r, &x);
        int cnt = 0;
        for(int i=l;i<=r;i++) {
            if(a[i] < a[x]) cnt ++;
        }
        if(cnt == x - l) printf("Yes\n");
        else printf("No\n");
    }
}