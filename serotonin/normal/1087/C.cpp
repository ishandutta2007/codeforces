#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int ara[1005][1005];

void pr(ll a, ll b, ll c, ll d)
{
    ll i,j;
    if(a<c) {
        for(i=a; i<=c; i++) ara[i][b]=1;
        if(b<d) for(i=b; i<=d; i++) ara[c][i]=1;
        else for(i=d; i<=b; i++) ara[c][i]=1;
    }
    else {
        for(i=c; i<=a; i++) ara[i][d]=1;
        if(b<d) for(i=b; i<=d; i++) ara[a][i]=1;
        else for(i=d; i<=b; i++) ara[a][i]=1;
    }
}

int main()
{
    ll i,j,k,xa,xb,xc,ya,yb,yc,x,y,p=sz;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll ans=abs(xa-xb)+abs(ya-yb)+1;
    if(xc>=min(xa,xb) && xc<=max(xa,xb) && yc>=min(ya,yb) && yc<=max(ya,yb)) {
        x=xc;
        y=yc;
    }
    else {
        for(i=min(xa,xb); i<=max(xa,xb); i++) {
            k=abs(i-xc)+abs(ya-yc);
            if(k<p) {
                p=k;
                x=i;
                y=ya;
            }
            k=abs(i-xc)+abs(yb-yc);
            if(k<p) {
                p=k;
                x=i;
                y=yb;
            }
        }
        for(i=min(ya,yb); i<=max(ya,yb); i++) {
            k=abs(xa-xc)+abs(i-yc);
            if(k<p) {
                p=k;
                x=xa;
                y=i;
            }
            k=abs(xb-xc)+abs(i-yc);
            if(k<p) {
                p=k;
                x=xb;
                y=i;
            }
        }
    }
    ans+=abs(x-xc)+abs(y-yc);
    cout << ans << endl;
    pr(xa,ya,x,y);
    pr(xb,yb,x,y);
    pr(xc,yc,x,y);
    for(i=0;i<1005;i++) {
        for(j=0;j<1005;j++) {
            if(ara[i][j]) printf("%lld %lld\n", i, j);
        }
    }
}