#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

int gl[N];
int mx[N];

int gll(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=gll(gl[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        gl[i]=i;
        mx[i]=i;
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        int x=gll(l),y=gll(r);
        if (x!=y)
        {
            gl[x]=y;
            mx[y]=max(mx[x],mx[y]);
        }
    }
    int mxx=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        if (i<=mxx&&gll(i)!=gll(i-1))
        {
            int c1=gll(i);
            int c2=gll(i-1);
            ans++;
            gl[c1]=c2;
            mx[c2]=max(mx[c2],mx[c1]);
        }
        mxx=max(mxx,mx[gll(i)]);
    }
    cout<<ans;
}

/**

**/