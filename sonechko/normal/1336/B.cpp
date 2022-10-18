#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll ans;

void ups(ll x, ll y, ll z)
{
    ans=min(ans,(x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z));
}

void upp(vector<ll> v1, vector<ll> v2, vector<ll> v3)
{
    int p2=0,p3=0;
    for (int i=0; i<v1.size(); i++)
    {
        while (p2+1<v2.size()&&v2[p2+1]<=v1[i])
            p2++;
        while (p3+1<v3.size()&&v3[p3]<v1[i])
            p3++;
        if (v2[p2]<=v1[i]&&v3[p3]>=v1[i]) ups(v1[i],v2[p2],v3[p3]);
    }
}

void up()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<ll> v1,v2,v3;
    for (int i=1; i<=n1; i++)
    {
        int l;
        cin>>l;
        v1.pb(l);
    }
    for (int i=1; i<=n2; i++)
    {
        int l;
        cin>>l;
        v2.pb(l);
    }
    for (int i=1; i<=n3; i++)
    {
        int l;
        cin>>l;
        v3.pb(l);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    ans=5e18;
    upp(v1,v2,v3);
    upp(v1,v3,v2);
    upp(v2,v1,v3);
    upp(v2,v3,v1);
    upp(v3,v1,v2);
    upp(v3,v2,v1);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**
x < y < z
y   

**/