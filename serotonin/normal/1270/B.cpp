#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        bool yes=0;
        int l,r;
        for(int i=1; i<n; i++) {
            if(abs(a[i]-a[i-1])>1) {
                yes=1;
                l=i-1, r=i;
            }
        }

        if(!yes) puts("NO");
        else {
            puts("YES");
            printf("%d %d\n", l+1, r+1);
        }
    }
}