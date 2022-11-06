#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5,p=1e9+7;

ll n,m,white,black;

void change(ll a, ll b, ll c, ll d, ll f)
{
    if(a>c || b>d) return;
    ll total=(c-a+1)*(d-b+1);
    ll cw,cb;
    cw=total/2;
    cb=cw;
    if(total%2) {
        if((a+b)%2) cb++;
        else cw++;
    }

    if(!f) {
        black-=cb;
        white+=cb;
    }
    else if(f==1) {
        black+=cb;
        white-=cb;
    }
    else if(f==2) {
        black+=cw;
        white-=cw;
    }
}

int main()
{
    ll q;
    cin >> q;
    while(q--)
    {
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &n,&m,&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        white=(n*m)/2;
        black=white;
        if(n%2 && m%2) white++;
        change(x1,y1,x2,y2,0);
        change(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4),1);
        change(x3,y3,x4,y4,2);
        printf("%I64d %I64d\n", white, black);
    }
}