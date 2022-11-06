#include<bits/stdc++.h>
using namespace std;

main() {
    double m,ans,frac=1,x,y;
    int n,i;
    scanf("%d %lf", &n, &m);

    for(i=0;i<n;i++) {
        scanf("%lf %lf", &x, &y);
        frac*=(1-(1/x));
        frac*=(1-(1/y));
    }

    if(frac==0.0) puts("-1");
    else {
        ans=(m/frac)-m;
        printf("%.8f\n", ans);
    }
}