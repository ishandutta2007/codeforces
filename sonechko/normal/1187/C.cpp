#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > v1;
    for (int i=1; i<=m; i++)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if (t==1)
        {
            for (int j=l; j<r; j++)
                a[j]=1;
        } else
        {
            v1.pb(mp(l,r));
        }
    }
    int p=1;
    for (int j=n; j>=1; j--)
    {
        a[j]=p;
        if (a[j-1]==0) p++;
    }
    for (int j=0; j<v1.size(); j++)
    {
        int l=v1[j].ff,r=v1[j].ss;
        int c=0;
        for (int p=l; p<r; p++)
            if (a[p]>a[p+1]) c=1;
        if (c==0) {cout<<"NO"; return 0;}
    }
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}