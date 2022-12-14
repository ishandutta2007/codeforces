#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < n; i ++) {
        if(i % 2 == 0) printf("%d ", a[i/2]);
        else printf("%d ", a[n - (i + 1) / 2]);
    }
}