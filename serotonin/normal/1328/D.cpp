#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz], ans[sz];

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        int n;
        scanf("%d", &n);
        bool done = 1;
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            if(i>1 && a[i]!=a[i-1]) done = 0;
        }
        if(done) for(int i=1; i<=n; i++) ans[i] = 0;
        else {
            if(a[1]!=a[n] && n%2) {
                for(int i=1; i<=n; i++) {
                    if(a[i]==a[i-1]) {
                        for(int j=1; j<i; j++) ans[j] = j & 1;
                        for(int j=i; j<=n; j++) ans[j] = 1 ^ j & 1;
                        done = 1;
                        break;
                    }
                }
                if(!done) {
                    for(int i=1; i<n; i++) ans[i] = i & 1;
                    ans[n] = 2;
                }
            }
            else
                for(int i=1; i<=n; i++) ans[i] = i & 1;
        }

        printf("%d\n", *max_element(ans+1, ans+n+1) + 1);
        for(int i=1; i<=n; i++) printf("%d ", ans[i] + 1);
        puts("");
    }
}