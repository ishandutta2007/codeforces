#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e6 + 11;

bool prost(int l)
{
    for (int i=2; i<=(int)sqrt(l); i++)
        if (l%i==0) return false;
    return true;
}

map<pair<int,int>,bool> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x=0;
    for (int i=n; ; i++)
    if (prost(i)) {x=i; break;}

    vector<pair<int,pair<int, int> > > v;
    v.pb(mp(1,mp(n,2)));
    for (int i=3; i<n; i++)
    {
        v.pb(mp(1,mp(i,1)));
    }
    if (n>=3)
    {
        v.pb(mp(1,mp(2,x-2-(n-3))));
    }
    int l=2,r=3;
    for (int i=n; i<=m; i++)
    {
        v.pb(mp(l,mp(r,1000000000)));
        r++;
        if (r==n+1) {l++; r=l+1;}
    }
    cout<<2<<" "<<x<<"\n";
    for (int i=0; i<v.size(); i++)
    cout<<v[i].ff<<" "<<v[i].ss.ff<<" "<<v[i].ss.ss<<"\n";
}