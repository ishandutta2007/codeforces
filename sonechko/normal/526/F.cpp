#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 3e5 + 11;

int a[N];
int v[N*4],k[N*4],w[N*4];

void push(int i)
{
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    v[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr)
    {
        v[i]+=x;
        w[i]+=x;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
    if (v[i+i]<v[i+i+1]) {v[i]=v[i+i]; k[i]=k[i+i];} else
    if (v[i+i+1]<v[i+i]) {v[i]=v[i+i+1]; k[i]=k[i+i+1];} else
    {
        v[i]=v[i+i];
        k[i]=k[i+i]+k[i+i+1];
    }
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        v[i]=l;
        k[i]=1;
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=v[i+i];
    k[i]=1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]=r;
    }
    build(1,1,n);
    ll ans=0;
    vector<pair<int,int> > mini,maxi;
    for (int i=1; i<=n; i++)
    {
        update(1,1,n,1,n,-1);
        ///cout<<1<<".."<<n<<" -1"<<endl;


        int l=i;
        while (mini.size()>0&&mini.back().ff>a[i])
        {
            update(1,1,n,mini.back().ss,l-1,mini.back().ff-a[i]);
            ///cout<<mini.back().ss<<".."<<l-1<<" "<<mini.back().ff-a[i]<<endl;
            l=mini.back().ss;
            mini.pop_back();
        }
        update(1,1,n,i,i,-a[i]);
        ///cout<<i<<".."<<i<<" -"<<a[i]<<endl;
        mini.pb(mp(a[i],l));


        l=i;
        while (maxi.size()>0&&maxi.back().ff<a[i])
        {
            update(1,1,n,maxi.back().ss,l-1,a[i]-maxi.back().ff);
            ///cout<<maxi.back().ss<<".."<<l-1<<" "<<a[i]-maxi.back().ff<<endl;
            l=maxi.back().ss;
            maxi.pop_back();
        }
        update(1,1,n,i,i,a[i]);
        ///cout<<i<<".."<<i<<" +"<<a[i]<<endl;
        maxi.pb(mp(a[i],l));
        ///cout<<"? "<<v[1]<<" "<<k[1]<<endl;
        if (v[1]==0) ans+=1ll*k[1];
    }

    cout<<ans<<endl;

}