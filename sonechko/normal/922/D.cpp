#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 2e5 + 11;

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if (a.ff*b.ss>a.ss*b.ff) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll d=0,ts=0;
    vector<pair<ll,ll> > p;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        ll k1=0,k2=0;
        for (int j=0; j<s.size(); j++)
        if (s[j]=='s') k1++; else {k2++; d+=1ll*k1;}
        p.pb(mp(k1,k2));
        ts+=k2;
    }
    sort(p.begin(),p.end(),cmp);
    for (int i=0; i<p.size(); i++)
    {
        ts-=p[i].ss;
        d+=p[i].ff*ts;
    }
    cout<<d<<endl;
}