#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;
ll a[sz],b[sz];

main()
{
    ll m,n,i,j,x=0,y=0,k;
    cin >> n;
    for(i=0;i<n;i++) {
        scanf("%I64d", &a[i]);
        x+=a[i];
    }
    cin >> m;
    for(i=0;i<m;i++) {
        scanf("%I64d", &b[i]);
        y+=b[i];
    }

    if(x!=y) {
        puts("-1");
        return 0;
    }

    i=0,j=0,k=0;
    for(;;)
    {
        x=a[i];
        y=b[j];
        for(;;) {
            if(x!=y) {
                if(x>y) {
                    j++;
                    y+=b[j];
                }
                else {
                    i++;
                    x+=a[i];
                }
            }
            else break;
        }
        i++;
        j++;
        k++;
        if(i==n || j==m) break;
    }
    printf("%I64d\n", k);
}