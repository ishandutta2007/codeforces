#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while(t --) {
        scanf("%d", &n);
        if(n < 3) puts("0");
        else printf("%d\n", n - 2);
    }
}