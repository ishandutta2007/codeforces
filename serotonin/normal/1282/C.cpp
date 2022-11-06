#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

pair <ll,ll> t[sz];

int main()
{
    int m;
    cin >> m;
    while(m--) {
        ll n,T,a,b,tota=0,totb=0;
        scanf("%lld %lld %lld %lld", &n, &T, &a, &b);
        for(ll i=0; i<n; i++) scanf("%lld", &t[i].second);
        for(ll i=0; i<n; i++) scanf("%lld", &t[i].first);
        for(ll i=0; i<n; i++) if(t[i].second) totb++;
        tota=n-totb;
        sort(t,t+n);

        if(tota*a+totb*b<=T) {
            printf("%lld\n", n);
            continue;
        }

        ll easy=0, hard=0, ans=0;
        for(ll i=0; i<n; ) {
            ll nowt=t[i].first-1-easy*a-hard*b;
            if(nowt>=0) {
                ll cnt=easy+hard;
                ll ra=tota-easy, rb=totb-hard;

                ll xa=nowt/a;
                if(xa>=ra) {
                    cnt+=ra;
                    nowt-=ra*a;
                    ll xb=nowt/b;
                    if(xb>=rb) cnt+=rb;
                    else cnt+=xb;
                }
                else {
                    cnt+=xa;
                }
                ans=max(ans, cnt);
            }

            ll j=i;
            while(i<n && t[j]==t[i]) {
                if(t[i].second) hard++;
                else easy++;
                i++;
            }
        }

        printf("%lld\n", ans);
    }
}