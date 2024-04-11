#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e4 + 11;

vector<int> v[N*5];
bitset<N> ans;

void up(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr)
    {
        v[i].pb(x);
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    up(i*2,l,mid,tl,tr,x);
    up(i*2+1,mid+1,r,tl,tr,x);
}

void build(int i, int l, int r, bitset<N> dd)
{
    for (int j=0; j<v[i].size(); j++)
        dd|=(dd<<v[i][j]);
    if (l==r) {ans|=dd; return;}
    int mid=(l+r)/2;
    build(i*2,l,mid,dd);
    build(i*2+1,mid+1,r,dd);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=q; i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        up(1,1,n,l,r,x);
    }
    bitset<N> a=0;
    a[0]=1;
    build(1,1,n,a);
    vector<int> vv;
    for (int j=1; j<=n; j++)
        if (ans[j]) vv.pb(j);
    cout<<vv.size()<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
    cout<<endl;
    /**
    for (int i=1; i<=n; i++)
    {
        bitset<100005> st,ss;
        st=0;
        ss=0;
        st[0]=1;
        for (int j=1; j<=q; j++)
            if (a[j]<=i&&b[j]>=i)
        {
            ss=st<<c[j];
            st|=ss;
        }
        for (int d=1; d<=n; d++)
            if (st[d]==1) cout<<d<<" ";
        cout<<endl;
    }
    **/
}