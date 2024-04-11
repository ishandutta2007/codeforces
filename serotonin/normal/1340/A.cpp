#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], w[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]), w[a[i]] = i;

        bool ok = 1;
        for(int i=2, j=w[1], k=w[1]; i<=n; i++) {
            int p = w[i];
            if(p != j+1) {
                if(p < k) {
                    j = k = p;
                }
                else ok = 0;
            }
            else j++;
        }

        if(ok) puts("YES");
        else puts("NO");
    }
}