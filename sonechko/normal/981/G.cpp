#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int mod = 998244353;

set<pair<int,int> > st[N];
ll w1[N*4],w2[N*4],v[N*4];

void push(int i, int l, int r, int mid)
{
    v[i*2]*=w1[i];
    v[i*2+1]*=w1[i];
    v[i*2]+=w2[i]*1ll*(mid-l+1);
    v[i*2+1]+=w2[i]*1ll*(r-mid);
    w1[i*2]*=w1[i];
    w1[i*2+1]*=w1[i];
    w2[i*2]*=w1[i];
    w2[i*2+1]*=w1[i];
    w2[i*2]+=w2[i];
    w2[i*2+1]+=w2[i];
    w1[i*2]%=mod;
    w2[i*2]%=mod;
    v[i*2]%=mod;
    w1[i*2+1]%=mod;
    w2[i*2+1]%=mod;
    v[i*2+1]%=mod;
    w1[i]=1;
    w2[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x, int y)
{
    if (tl<=l&&r<=tr)
    {
        v[i]*=x;
        v[i]+=y*1ll*(r-l+1);
        w1[i]*=x;
        w2[i]*=x;
        w2[i]+=y;
        w1[i]%=mod;
        w2[i]%=mod;
        v[i]%=mod;
        //cout<<"! "<<l<<" "<<r<<" "<<v[i]<<" "<<w1[i]<<" "<<w2[i]<<endl;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i*2,l,mid,tl,tr,x,y);
    update(i*2+1,mid+1,r,tl,tr,x,y);
    v[i]=v[i*2]+v[i*2+1];
    v[i]%=mod;
    //cout<<"! "<<l<<" "<<r<<" "<<v[i]<<" "<<w1[i]<<" "<<w2[i]<<endl;
}

int sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 0;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    return (sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr))%mod;
}

void build(int i, int l, int r)
{
    v[i]=0;
    w1[i]=1;
    w2[i]=0;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    for (int i=1; i<=q; i++)
    {
        int t;
        cin>>t;
        if (t==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(1,1,n,l,r)<<"\n";
        } else
        {
            int l,r,x;
            cin>>l>>r>>x;
            update(1,1,n,l,r,1,1);
            int last=l;
            int l1=l,r1=r;
            set<pair<int,int> > :: iterator it=st[x].upper_bound(mp(l,0));
            if (it!=st[x].begin())
            {
                it--;
                if (it->ss>=l)
                {
                    //cout<<"- "<<it->ff<<" "<<it->ss<<endl;
                    update(1,1,n,max(l,it->ff),min(r,it->ss),1,-1);
                    update(1,1,n,max(l,it->ff),min(r,it->ss),2,0);
                    st[x].erase(it);
                    l1=min(l1,it->ff);
                    r1=max(r1,it->ss);
                }
            }
            while (1==1)
            {
                it=st[x].upper_bound(mp(l,0));
                if (it->ff>r) break;
                if (it==st[x].end()) break;
                //cout<<"- "<<it->ff<<" "<<it->ss<<endl;
                update(1,1,n,max(l,it->ff),min(r,it->ss),1,-1);
                update(1,1,n,max(l,it->ff),min(r,it->ss),2,0);
                l1=min(l1,it->ff);
                r1=max(r1,it->ss);
                st[x].erase(it);
            }
            //cout<<"+ "<<l<<" "<<r<<endl;
            st[x].insert(mp(l1,r1));
        }
    }
}