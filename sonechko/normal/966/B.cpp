#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;

pair<ll,int> a[N];

ll p[N],g[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll x1,x2;
    cin>>n>>x1>>x2;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        a[i]=mp(l,i);
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        int cc=(x1+a[i].ff-1)/a[i].ff;
        p[i]=n-i+1-cc;
        g[i]=i;
        if (i!=1&&p[i-1]>p[i])
        {
            p[i]=p[i-1];
            g[i]=g[i-1];
        }
    }
    for (int i=n; i>=2; i--)
    {
        int cc=(x2+a[i].ff-1)/a[i].ff;
        int pos=g[i-1];
        int dd=(x1+a[pos].ff-1)/a[pos].ff;
        int pp=max(0,dd-(i-pos));
        if (pp+cc<=n-i+1)
        {
            cout<<"Yes"<<endl;
            cout<<dd<<" "<<cc<<endl;
            for (int ii=pos; ii<=pos+dd-1; ii++)
                cout<<a[ii].ss<<" ";
            cout<<endl;
            for (int ii=max(pos+dd,i); ii<=max(pos+dd,i)+cc-1; ii++)
                cout<<a[ii].ss<<" ";
            cout<<endl;
            return 0;
        }
    }
    swap(x1,x2);
    for (int i=1; i<=n; i++)
    {
        int cc=(x1+a[i].ff-1)/a[i].ff;
        p[i]=n-i+1-cc;
        g[i]=i;
        if (i!=1&&p[i-1]>p[i])
        {
            p[i]=p[i-1];
            g[i]=g[i-1];
        }
    }
    for (int i=n; i>=2; i--)
    {
        int cc=(x2+a[i].ff-1)/a[i].ff;
        int pos=g[i-1];
        int dd=(x1+a[pos].ff-1)/a[pos].ff;
        int pp=max(0,dd-(i-pos));
        if (pp+cc<=n-i+1)
        {
            cout<<"Yes"<<endl;
            cout<<cc<<" "<<dd<<endl;
            for (int ii=max(pos+dd,i); ii<=max(pos+dd,i)+cc-1; ii++)
                cout<<a[ii].ss<<" ";
            cout<<endl;
            for (int ii=pos; ii<=pos+dd-1; ii++)
                cout<<a[ii].ss<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}