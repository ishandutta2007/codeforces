#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, od = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            if(a[i] & 1) od++;
        }
        if(od & 1) {
            sort(a,a+n);
            int ans = sz;
            for(int i=1; i<n; i++) if(a[i] ^ a[i-1]) ans = min(ans, a[i]-a[i-1]);
            if(ans > 1) {
                puts("NO");
                continue;
            }
        }
        puts("YES");
    }
}