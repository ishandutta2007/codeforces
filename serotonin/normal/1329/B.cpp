#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5005;

int a[35];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int d, m;
        scanf("%d %d", &d, &m);

        memset(a, 0, sizeof a);
        for(int i=1; ; i++) {
            int x = 1 << i;
            a[i] = x >> 1;
            if(x > d) {
                a[i] -= x - d - 1;
                break;
            }
        }

        int ans = 0;
        for(int i=32; i; i--) {
            a[i] %= m;
            ll now = 1;
            for(int j=i+1; j<32; j++) {
                now += a[j];
                now %= m;
            }
            a[i] = now * a[i] % m;
            ans += a[i];
            ans %= m;
        }

        printf("%d\n", ans);
    }
}