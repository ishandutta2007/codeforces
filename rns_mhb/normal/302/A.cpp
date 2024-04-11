#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    int n, q, i, l, r;
    scanf("%d%d", &n, &q);
    while(n --) {
        scanf("%d", &a);
        if(a == 1) b ++;
        else c ++;
    }
    while(q --) {
        scanf("%d%d", &l, &r);
        printf("%d\n", (r - l & 1 && (r - l + 1) / 2 <= min(b, c)));
    }
}