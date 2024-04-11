#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
const int N = 1e3 + 11;
int a[N];
vector<pair<int,int> > v;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=m; i++)
    {
        int l=1,r=1;
        for (int j=1; j<=n; j++)
        {
            if (a[j]<a[l]) l=j;
            if (a[j]>a[r]) r=j;
        }
        if (a[l]==a[r]) break;
        a[r]--;
        a[l]++;
        v.pb(mp(r,l));
    }
    int l=1,r=1;
    for (int i=1; i<=n; i++)
    {
        if (a[i]<a[l]) l=i;
        if (a[i]>a[r]) r=i;
    }
    cout<<a[r]-a[l]<<" "<<v.size()<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i].ff<<" "<<v[i].ss<<endl;
}