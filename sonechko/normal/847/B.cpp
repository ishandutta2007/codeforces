#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define sqr(a) ((a)*(a))
#define y1 y12312312
#define int ll
#define endl '\n'

using namespace std;
const int N=200001;
const int inf=1e9+3;
const int md=1e9+7;
const ll linf = 1e18;

int n,a[N],d[N*4],num,sz,pos;
vector< vector<int> > ans;

void update(int v,int x)
{
    v+=sz-1;
    d[v]=x;
    v/=2;
    while(v)
    {
        d[v]=min(d[v+v],d[v+v+1]);
        v/=2;
    }
}

int get_pos(int v,int l,int r,int l_v,int r_v,int x)
{
    if(l>r||l>r_v||r<l_v||d[v]>=x)return -1;
    if(l==r)return l;
    int mid=(l+r)/2;
    int z=get_pos(v+v,l,mid,l_v,r_v,x);
    if(z!=-1)return z;
    return get_pos(v+v+1,mid+1,r,l_v,r_v,x);
}

main()
{
    bs
    cin>>n;

    sz=1;
    while(sz<n)sz*=2;
    for(int i=1;i<=sz*2;++i)d[i]=inf;

    vector<int> g;
    for(int i=0;i<n;++i)
    {
        ans.pb(g);
    }

    for(int i=1;i<=n;++i)
    {
        cin>>a[i];

            pos=get_pos(1,1,sz,1,sz,a[i]);
            if(pos==-1)
            {
                pos=++num;
            }


        update(pos,a[i]);
        ans[pos-1].pb(a[i]);
    }
    for(int i=0;i<n;++i)
    {
        if(ans[i].size()==0)break;
        for(int j=0;j<ans[i].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}