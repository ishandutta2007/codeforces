#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

ll a[sz];

struct data {
    ll pos,ag,off;
} trp[sz];

bool cmp(data a, data b)
{
    if(a.pos == b.pos) return a.off > b.off;
    return a.pos < b.pos;
}

int main()
{
    ll m,n,k,t;
    cin >> m >> n >> k >> t;
    for(ll i=0; i<m; i++) scanf("%lld", &a[i]);
    sort(a,a+m,greater<ll>());
    for(ll i=0; i<k; i++) scanf("%lld %lld %lld", &trp[i].pos, &trp[i].off, &trp[i].ag);
    /* FUUUUUUCCCCCCCCKKKKKKKKKKK MYYYYYYYYYYYYYYYYYYYYYY LIIIIIIIIIIIIIIIIFFFFFFFE  */
    sort(trp, trp+k, cmp);

    ll low=0, high=m;
    while(low<high) {
        ll mid=(low+high+1)>>1;
        ll smolag=a[mid-1];
        ll tot=0,now=0;
        for(ll i=0; i<k; i++) {
            ll last=trp[i].pos, newi=i;
            bool yes=0;
            for(ll j=i; j<k; j++) {
                if(last < trp[j].pos) break;
                if(trp[j].ag>smolag) {
                    yes=1;
                    last=max(last, trp[j].off);
                }
                newi=j;
            }

            if(yes) {
                tot+=(last-trp[i].pos+1)<<1;
                i=newi;
                tot+=trp[i].pos-now;
                now=trp[i].pos;
            }
            else {
                i=newi;
                tot+=trp[i].pos-now;
                now=trp[i].pos;
            }
        }
        tot+=n+1-now;

        if(tot<=t) low=mid;
        else high=mid-1;
    }
    printf("%lld\n", high);
}