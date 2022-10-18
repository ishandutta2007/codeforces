#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

map<ll,int> kol1,kol2;
ll kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<ll> v;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        if (kol1[l]==0&&kol2[l]==0) v.pb(l);
        kol1[l]++;
        if (kol2[r]==0&&kol1[r]==0) v.pb(r);
        kol2[r]++;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for (int j=0; j<v.size(); j++)
    {
        ll l=v[j];
        ans+=kol1[l];
        kol[ans]++;
        ans-=kol2[l];
        if (ans!=0) kol[ans]+=v[j+1]-v[j]-1;
    }
    for (int i=1; i<=n; i++)
        cout<<kol[i]<<" ";
    cout<<endl;
}