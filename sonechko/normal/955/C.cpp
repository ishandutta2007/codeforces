#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 5e5 + 11;
map<ll,bool> mt;
vector<ll> v;

bool sq(ll h)
{
    ll d=(ll)sqrt((ld)h);
    if (d*d==h) return true;
    return false;
}

ll find_(ll x)
{
    int l=0,r=v.size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (v[mid]<=x) l=mid; else r=mid;
    }
    if (v[r]<=x) return r+1;
    if (v[l]<=x) return l+1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    srand(time(NULL));
    for (ll i=2; i<=1000000; i++)
    {
        ll j=i*i*i;
        while (j<=1000000000000000000)
        {
            if (mt[j]==0&&(!(sq(j)))) {mt[j]=1; v.pb(j);}
            if (1000000000000000000/j<i-2) break;
            j*=i;
        }
    }
    sort(v.begin(),v.end());
    for (int p=1; p<=q; p++)
    {
        ll l,r;
        cin>>l>>r;
        ll res=floor(sqrt((ld)r))-floor(sqrt((ld)(l-1)));
        //cout<<(ll)floor(sqrt((ld)r))<<" "<<(ll)floor(sqrt((ld)(l-1)))<<endl;
        //cout<<find_(r)<<" "<<find_(l-1)<<endl;
        res+=find_(r)-find_(l-1);
        cout<<res<<"\n";
    }
}