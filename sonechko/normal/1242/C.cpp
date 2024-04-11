#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int k;
ll sum;
vector<ll> v[N];
int g[N];
int pr1[N],pr2[N];
ll s[N];
map<ll,int> mt;
pair<ll,ll> res[N];

bool get(int mask)
{
    if (g[mask]==1) return true;
    if (g[mask]==2) return false;
    if (mask==0) return true;
    int t=0;
    for (int i=1; i<=k; i++)
        if (mask&(1<<(i-1))) {t=i; break;}
    for (int j=0; j<v[t].size(); j++)
    {
        int mask2=mask;
        ll need=sum-(s[t]-v[t][j]);
        ll ost=v[t][j];
        int t1=t;
        while (1)
        {
            if (mt.find(need)==mt.end()) {mask2=-1; break;}
            mask2^=(1<<(t1-1));
            int t2=mt[need];
            if (t2==t&&need==ost) break;
            if (t2==t&&need!=ost) {mask2=-1; break;}
            if ((mask2&(1<<(t2-1)))==0) {mask2=-1; break;}
            need=sum-(s[t2]-need);
            t1=t2;
        }
        if (mask2==-1) continue;
        if (get(mask2)) {g[mask]=1; pr1[mask]=t; pr2[mask]=j; return 1;}
    }
    g[mask]=2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>k;
    for (int i=1; i<=k; i++)
    {
        int t;
        cin>>t;
        for (int j=1; j<=t; j++)
        {
            ll x;
            cin>>x;
            v[i].pb(x);
            sum+=x;
            mt[x]=i;
            s[i]+=x;
        }
    }
    if (sum%k!=0) {cout<<"No"; return 0;}
    sum/=k;
    int d=get((1<<k)-1);
    if (d==0) {cout<<"No"; return 0;}
    int mask=(1<<k)-1;
    while (mask!=0)
    {
        int mask2=mask;
        int t=pr1[mask];
        int j=pr2[mask];
        ll need=sum-(s[t]-v[t][j]);
        ll ost=v[t][j];
        int t1=t;
        while (1)
        {
            mask2^=(1<<(t1-1));
            int t2=mt[need];
            res[t2]=mp(need,t1);
            if (t2==t&&need==ost) break;
            need=sum-(s[t2]-need);
            t1=t2;
        }
        mask=mask2;
    }
    cout<<"Yes\n";
    for (int i=1; i<=k; i++)
        cout<<res[i].ff<<" "<<res[i].ss<<"\n";
}