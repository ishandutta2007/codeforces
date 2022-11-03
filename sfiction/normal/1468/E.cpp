#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    int a[4];
    scanf("%d",&T);
    while(T--) {
        for (int i=0;i<4;i++) {
            scanf("%d",&a[i]);
        }
        sort(a,a+4);
        int ans = 0;
        do {
            ans = max(ans, min(a[0], a[1]) * min(a[2], a[3]));
        } while(next_permutation(a, a + 4));
        printf("%d\n",ans);
    } 
}