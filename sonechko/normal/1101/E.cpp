#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int xx[N],yy[N],pos[N];

pair<int,int> v[N*4];

void update(int i, int l, int r, int x, pair<int,int> p)
{
    if (l==r) {v[i]=p; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,p); else update(i*2+1,mid+1,r,x,p);
    v[i].ff=max(v[i*2].ff,v[i*2+1].ff);
    v[i].ss=max(v[i*2].ss,v[i*2+1].ss);
}

pair<int,int> get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return mp(0,0);
    int mid=(l+r)/2;
    pair<int,int> p1=get(i*2,l,mid,tl,tr),p2=get(i*2+1,mid+1,r,tl,tr);
    return mp(max(p1.ff,p2.ff),max(p1.ss,p2.ss));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    vector<pair<pair<int,int>,int> > vv;
    for (int i=1; i<=q; i++)
    {
        char ch;
        cin>>ch;
        if (ch=='+')
        {
            int x,y;
            cin>>x>>y;
            xx[i]=-1;
            yy[i]=-1;
            if (x>y) swap(x,y);
            vv.pb(mp(mp(x,y),i));
        } else 
        {
            cin>>xx[i]>>yy[i];
            if (xx[i]>yy[i]) swap(xx[i],yy[i]);
        }
    }
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    pos[vv[j].ss]=j;
    for (int i=1; i<=q; i++)
        if (xx[i]==-1) update(1,1,vv.size(),pos[i]+1,vv[pos[i]].ff); else 
        {
            int x=xx[i],y=yy[i];
            int l=0,r=vv.size()-1;
            while (r-l>1)
            {
                int mid=(l+r)/2;
                if (vv[mid].ff.ff>x) r=mid; else l=mid;
            }
            if (vv[r].ff.ff<=x) l=r;
            if (vv[l].ff.ff>x) l=-1;
            int mx=get(1,1,vv.size(),1,l+1).ss;
            int ans=1;
            if (mx>y) ans=-1;
            pair<int,int> mxx=get(1,1,vv.size(),l+2,vv.size());
            if (mxx.ff>y) ans=-1;
            if (mxx.ss>x) ans=-1;
            if (ans==-1) cout<<"NO\n"; else cout<<"YES\n";
        }
        
}