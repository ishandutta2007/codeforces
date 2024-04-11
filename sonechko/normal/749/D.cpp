#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int a[N],b[N],c[N],v[N*5],f[N],g[N];
vector<int> w[N];
void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=x; c[x]=t; return;}
    int d=(l+r)/2;
    if (x<=d) update(i*2,l,d,x,t); else update(i*2+1,d+1,r,x,t);
    if (c[v[i*2]]>c[v[i*2+1]]) v[i]=v[i*2]; else v[i]=v[i*2+1];
}
int main()
{
    sync;
    #ifdef LOCAL
    #else
    #endif
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i]>>b[i];
            g[a[i]]=b[i];
            update(1,1,n,a[i],b[i]);
            w[a[i]].pb(b[i]);
        }
    int m;
    cin>>m;
    for (int j=1; j<=m; j++)
    {
        int k;
        cin>>k;
        for (int i=1; i<=k; i++)
        {
            cin>>f[i];
            update(1,1,n,f[i],0);
        }
        int ans1=v[1];
        if (c[ans1]==0) {cout<<"0 0"<<endl;} else
            {
                update(1,1,n,ans1,0);
                if (c[v[1]]==0) {cout<<ans1<<" "<<w[ans1][0]<<endl;} else
                    {
                        int l=0,r=w[ans1].size()-1;
                        while(r-l>1)
                        {
                            int mid=(l+r)/2;
                            if (w[ans1][mid]>c[v[1]]) r=mid; else l=mid;
                        }
                        if (w[ans1][l]>c[v[1]]) r=l;
                        cout<<ans1<<" "<<w[ans1][r]<<endl;
                    }
                update(1,1,n,ans1,g[ans1]);
            }
        for (int i=1; i<=k; i++)
        {
            update(1,1,n,f[i],g[f[i]]);
        }
    }
}