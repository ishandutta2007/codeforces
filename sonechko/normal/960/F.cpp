#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 1e5 + 11;

int tin[N],tout[N],a[N],b[N],c[N],num[N];
int v[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v[i]=max(v[i*2],v[i*2+1]);
}
int maxi(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    return max(maxi(i*2,l,mid,tl,tr),maxi(i*2+1,mid+1,r,tl,tr));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        vv.pb(mp(a[i],mp(c[i],i)));
    }
    sort(vv.begin(),vv.end());
    for (int i=1; i<=n; i++)
        tin[i]=-1;
    for (int i=0; i<vv.size(); i++)
    {
        if (tin[vv[i].ff]==-1) tin[vv[i].ff]=i;
        tout[vv[i].ff]=i;
        num[vv[i].ss.ss]=i;
    }
    for (int i=m; i>=1; i--)
    {
        int nums=num[i];
        int l1=tin[b[i]],r1=tout[b[i]];
        int res=1;
        if (l1!=-1)
        {
            int l=l1,r=r1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (vv[mid].ss.ff>c[i]) r=mid; else l=mid;
            }
            if (vv[l].ss.ff>c[i]) {
            res=maxi(1,0,vv.size()-1,l,r1)+1; } else
            if (vv[r].ss.ff>c[i]) {
            res=maxi(1,0,vv.size()-1,r,r1)+1; }
        }
        update(1,0,vv.size()-1,nums,res);
    }
    cout<<v[1]<<endl;
}