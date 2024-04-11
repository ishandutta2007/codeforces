#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5, inf=1e15;

ll sc[sz], tall;
ll close[sz][2];
vector <ll> pnt[sz];
map <ll,ll> mp[sz];

ll fnc(ll x, ll y)
{
    //printf("%lld %lld\n",x ,y);

    if(x>tall) return 0;

    if(mp[x].find(y)!=mp[x].end()) return mp[x][y];

    ll ans=inf, z=pnt[x].size();

    if(z) {
        ll d[4],r,l;
        ll b=pnt[x][0], e=pnt[x][z-1];

        if(x<tall) {
            memset(d, -1, sizeof d);
            r=1, l=1;
            if(close[e][1]>0) d[3]=close[e][1]-e+fnc(x+1,close[e][1]);
            if(close[e][0]>0) d[2]=e-close[e][0]+fnc(x+1,close[e][0]);
            if(close[b][1]>0) d[1]=close[b][1]-b+fnc(x+1,close[b][1]);
            if(close[b][0]>0) d[0]=b-close[b][0]+fnc(x+1,close[b][0]);
        }
        else {
            memset(d, 0, sizeof d);
            r=0, l=0;
        }

        if(b>=y) {
            r+=e-y;
            if(d[3]>=0) ans=min(ans, r+d[3]);
            if(d[2]>=0) ans=min(ans, r+d[2]);
        }
        else if(e<=y) {
            l+=y-b;
            if(d[1]>=0) ans=min(ans, l+d[1]);
            if(d[0]>=0) ans=min(ans, l+d[0]);
        }
        else {
            r+=e-y+(y-b)*2;
            if(d[3]>=0) ans=min(ans, r+d[3]);
            if(d[2]>=0) ans=min(ans, r+d[2]);

            l+=y-b+(e-y)*2;
            if(d[1]>=0) ans=min(ans, l+d[1]);
            if(d[0]>=0) ans=min(ans, l+d[0]);
        }
    }
    else {
        /* F U C K            M Y             L I F E */
        if(close[y][0]>0) ans=min(ans, y-close[y][0]+1+fnc(x+1,close[y][0]));
        if(close[y][1]>0) ans=min(ans, close[y][1]-y+1+fnc(x+1,close[y][1]));
        /* F U C K            M Y             L I F E */
    }

    return mp[x][y]=ans;
}

int main()
{
    ll n,m,k,q;
    cin >> n >> m >> k >> q;
    for(ll i=0; i<k; i++) {
        ll x,y;
        scanf("%lld %lld", &x, &y);
        pnt[x].push_back(y);
        tall=max(tall, x);
    }
    for(ll i=0; i<q; i++) scanf("%lld", &sc[i]);

    for(ll i=1; i<=tall; i++) sort(pnt[i].begin(), pnt[i].end());
    sort(sc, sc+q);

    for(ll i=0; i<q; i++) {
        close[sc[i]][0]=sc[i], close[sc[i]][1]=sc[i];
        if(!i) {
            for(ll j=sc[i]-1; j; j--) close[j][0]=-1, close[j][1]=sc[i];
        }
        else if(i<q-1) {
            for(ll j=sc[i]-1; j>sc[i-1]; j--) close[j][0]=sc[i-1], close[j][1]=sc[i];
        }
        else {
            /* M   Y      G   O   D   D   A   M   N      D   U   M   B   A   S   S */
            for(ll j=sc[i]-1; j>sc[i-1]; j--) close[j][0]=sc[i-1], close[j][1]=sc[i];
            for(ll j=sc[i]+1; j<=m; j++) close[j][0]=sc[i], close[j][1]=-1;
        }
    }

    cout << fnc(1,1);
}