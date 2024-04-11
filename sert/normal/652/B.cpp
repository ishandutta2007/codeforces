#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 34;
int n;
int a[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d ", (i % 2 ? a[n - i / 2 - 1] : a[i / 2]));
}