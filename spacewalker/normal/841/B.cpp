#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; scanf("%d", &n);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int k; scanf("%d", &k);
        x |= k;
    }
    if (x & 1) printf("First\n");
    else printf("Second\n");
    return 0;
}