#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> v[N];
int a[N],b[N],d[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            v[i].clear();
            d[i]=-1;
        }
        for (int i=1; i<n; i++)
        {
            int l,r;
            cin>>l>>r;
            v[l].pb(r);
            v[r].pb(l);
        }
        int k1,k2;
        cin>>k1;
        for (int i=1; i<=k1; i++)
            cin>>a[i];
        cin>>k2;
        for (int i=1; i<=k2; i++)
            cin>>b[i];
        cout<<"B "<<b[1]<<endl;
        int x;
        cin>>x;
        vector<int> vv;
        vv.pb(x);
        d[x]=0;
        for (int j=0; j<vv.size(); j++)
        {
            int l=vv[j];
            for (int j=0; j<v[l].size(); j++)
                if (d[v[l][j]]==-1)
            {
                d[v[l][j]]=d[l]+1;
                vv.pb(v[l][j]);
            }
        }
        int p=a[1];
        for (int i=1; i<=k1; i++)
            if (d[a[i]]<d[p]) p=a[i];
        cout<<"A "<<p<<endl;
        cin>>x;
        int y=0;
        for (int i=1; i<=k2; i++)
        if (b[i]==x) {y=1; break;}
        if (y==1) cout<<"C "<<p<<endl; else cout<<"C "<<-1<<endl;
    }
}