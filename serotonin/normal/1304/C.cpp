#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=105;


int main()
{
    int q;
    cin >> q;
    while(q--) {
        ll n,m;
        scanf("%lld %lld", &n, &m);

        bool no=0;
        ll low=m, high=m, tb=0;
        for(int i=0; i<n; i++) {
            ll t,x,y;
            scanf("%lld %lld %lld", &t, &x, &y);
            ll d=t-tb;
            tb=t;
            low-=d, high+=d;

//            printf("%lld %lld\n", low, high);
            if(low>y || high<x) no=1;
            low=max(low,x);
            high=min(high,y);
//            printf("new : %lld %lld\n", low, high);

            if(low>high) no=1;
        }

        if(no) puts("NO");
        else puts("YES");
    }
}