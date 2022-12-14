#include <iostream>
using namespace std;
int main()
{
    int t, n, m, x, f[101];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for(int i=0; i<=100; i++) f[i] = 0;
        for(int i=1; i<=n+m; i++) scanf("%d", &x), f[x] = 1;
        int sum = 0; for(int i=0; i<=100; i++) sum += f[i];
        cout << n + m - sum << '\n';
    }
}