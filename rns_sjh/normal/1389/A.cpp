#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(r < 2 * l) puts("-1 -1");
        else printf("%d %d\n", l, 2 * l);
    }
}