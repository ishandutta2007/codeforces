#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

pair<int,int> a[N];
int b[N];
vector<int> v[N];
int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
        b[i]=a[i].ff;
    }
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    sort(a+1,a+n+1);
    int ps=0;
    for (int i=1; i<=n; i++)
    {
        int d=a[i].ss;
        while (ps<i-1&&a[ps+1].ff!=a[i].ff)
            ps++;
        int rr=ps;
        for (int j=0; j<v[d].size(); j++)
            if (b[v[d][j]]<b[d]) rr--;
        res[d]=rr;
    }
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}