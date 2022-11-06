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
        int n, x;
        scanf("%d %d", &n, &x);
        bool yes = 0;
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            if(a[i] == x) yes = 1;
        }

        if(!yes) {
            puts("no");
            continue;
        }

        if(n == 1) {
            puts("yes");
            continue;
        }

        yes = 0;
        for(int i=0; i<n; i++) {
            if(a[i] >= x) {
                if(i < n-1 && a[i+1] >= x) yes = 1;
                if(i < n-2 && a[i+2] >= x) yes = 1;
            }
        }

        if(yes) puts("yes");
        else puts("no");
    }
}