#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    scanf("%d", &n);
    if(n % 2 == 0) {
        int k = n >> 1;
        ans = (k + 1) * (k + 1);
    }
    else {
        int k = n >> 1;
        ans = 2 * (k + 1) * (k + 2);
    }
    printf("%d\n", ans);
}