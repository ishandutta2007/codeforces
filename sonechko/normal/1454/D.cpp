#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

ll a[N];

void up()
{
    ll n;
    cin>>n;
    vector<pair<int,ll> > v;
    ll d=2;
    while (d*d<=n)
    {
        int k=0;
        while (n%d==0)
        {
            k++;
            n/=d;
        }
        if (k>0) v.pb(mp(k,d));
        d++;
    }
    if (n>1) v.pb(mp(1,n));
    sort(v.begin(),v.end());
    int x=v.back().ff;
    for (int i=1; i<=x; i++)
        a[i]=1;
    for (int ii=0; ii<v.size(); ii++)
    {
        ll y=v[ii].ss;
        for (int i=x-v[ii].ff+1; i<=x; i++)
            a[i]*=y;
    }
    cout<<x<<"\n";
    for (int i=1; i<=x; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**
2 2 2 2
3 3 3
7
9 9
2 2 2 2
1 3 3 3
1 1 1 7
1 1 9 9
**/