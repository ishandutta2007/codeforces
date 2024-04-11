#include <iostream>
using namespace std;
int n, m;
int a[102],b[102];
int main() {
    cin>>n>>m;
    bool fg = 1; int mx = 0;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        if (i >= 2 && a[i] > mx) fg = 0;
        mx = max(mx, b[i]);
    }
    if (mx < m || a[1] > 0) fg = 0;
    printf("%s\n", fg?"YES":"NO");
}