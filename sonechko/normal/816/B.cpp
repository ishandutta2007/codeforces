#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 2e5 + 11;

vector<pair<int,int> > v;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,kk,q;
    cin>>n>>kk>>q;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        v.pb(mp(l,0));
        v.pb(mp(r,1));
    }
    sort(v.begin(),v.end());
    int i=0,p=0;
    for (int k=1; k<=200000; k++)
    {
        while (i<v.size()&&v[i].ss==0&&v[i].ff==k)
        {
            p++;
            i++;
        }
        if (p>=kk) a[k]=a[k-1]+1; else a[k]=a[k-1];
        while (i<v.size()&&v[i].ff==k)
        {
            p--;
            i++;
        }
    }
    for (int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<"\n";
    }
}