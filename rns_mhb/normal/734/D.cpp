#include<bits/stdc++.h>
#define inf 3000000010
#define N 501000
using namespace std;
char c[N];
int i,f;
long long x[N],y[N],kx,ky,mn;
main(){
    int q;
    scanf("%d",&q);
    scanf("%I64d%I64d",&kx,&ky);
    for(i = 1; i <= q; i ++)
        scanf("\n%c%I64d%I64d",c+i,x+i,y+i);
    for(mn = inf,i = 1; i <= q; i++)
            if(x[i] - kx >0 && y[i] == ky && mn > x[i] - kx) mn = x[i] - kx,f = i;
    if(mn != inf && (c[f] =='R' || c[f] == 'Q')){puts("YES");return 0;}

    for(mn = inf , i = 1 ; i <= q ; i++)
            if(x[i] - kx <0 && y[i] == ky && mn > kx - x[i]) mn = kx - x[i],f = i;
    if(mn != inf && (c[f] =='R' || c[f] == 'Q')){puts("YES");return 0;}


    for(mn = inf , i = 1 ; i <= q ; i++)
            if(y[i] - ky <0 && x[i] == kx && mn > ky - y[i]) mn = ky - y[i],f = i;
    if(mn != inf && (c[f] =='R' || c[f] == 'Q')){puts("YES");return 0;}


    for(mn = inf , i = 1 ; i <= q ; i++)
            if(y[i] - ky >0 && x[i] == kx && mn > y[i] - ky) mn = y[i] - ky,f = i;
    if(mn != inf && (c[f] =='R' || c[f] == 'Q')){puts("YES");return 0;}


    for(mn = inf,i = 1; i <= q; i++)
            if(x[i] - kx >0 && y[i] - ky == x[i] - kx && mn > x[i] - kx) mn = x[i] - kx,f = i;
    if(mn != inf && (c[f] =='Q' || c[f] == 'B')){puts("YES");return 0;}

    for(mn = inf,i = 1; i <= q; i++)
            if(x[i] - kx <0 && y[i] - ky == x[i] - kx && mn > kx - x[i]) mn = kx - x[i],f = i;
    if(mn != inf && (c[f] =='Q' || c[f] == 'B')){puts("YES");return 0;}

    for(mn = inf,i = 1; i <= q; i++)
            if(x[i] - kx >0 && ky -y[i] == x[i] - kx && mn > x[i] - kx) mn = x[i] - kx,f = i;
    if(mn != inf && (c[f] =='Q' || c[f] == 'B')){puts("YES");return 0;}

    for(mn = inf,i = 1; i <= q; i++)
            if(x[i] - kx <0 && ky - y[i] == x[i] - kx && mn > kx - x[i]) mn = kx - x[i],f = i;
    if(mn != inf && (c[f] =='Q' || c[f] == 'B')){puts("YES");return 0;}

    puts("NO");
}