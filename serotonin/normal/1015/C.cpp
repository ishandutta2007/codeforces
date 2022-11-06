#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using std::vector;

ll a[100005],b[100005],c[100005];

main()
{
    ll x,y,z,i,j,k,f,ans,n,m;
    scanf("%I64d %I64d", &n, &m);
    x=0;
    y=0;
    for(i=0;i<n;i++) {
        scanf("%I64d %I64d", &a[i], &b[i]);
        x+=a[i];
        y+=b[i];
        c[i]=a[i]-b[i];
    }
    if(y>m) puts("-1");
    else if(x<=m) puts("0");
    else {
        sort(c, c+n);
        k=0;
        for(i=n-1;i>=0;i--) {
            k++;
            x-=c[i];
            if(x<=m) break;
        }
        printf("%I64d\n", k);
    }
}