#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

bitset <sz> vis;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,d=0;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            int c,mn=n+1;
            scanf("%d", &c);
            if(!c) d=i;
            else {
                while(c--) {
                    int x;
                    scanf("%d", &x);
                    if(!vis[x]) mn=min(x,mn);
                }
                if(mn<=n) vis[mn]=1;
                else d=i;
            }
        }

        if(!d) puts("OPTIMAL");
        else {
            puts("IMPROVE");
            int s;
            for(int i=1; i<=n; i++) if(!vis[i]) s=i;
            printf("%d %d\n", d, s);
        }

        for(int i=1; i<=n; i++) vis[i]=0;
    }
}