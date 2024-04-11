#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N];
int v[N*4];
int nx[N],dp[N];

void update(int i, int l, int r, int x, int p)
{
    if (l==r) {v[i]=p; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,p); else update(i+i+1,mid+1,r,x,p);
    v[i]=v[i+i]+v[i+i+1];
}

int get(int i, int l, int r, int pos)
{
    if (v[i]==0) return -1;
    if (pos>r) return -1;
    if (l==r) return l;
    int mid=(l+r)/2;
    int c=get(i+i,l,mid,pos);
    if (c!=-1) return c;
    return get(i+i+1,mid+1,r,pos);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    int p=-1;
    for (int i=0; i<vv.size(); i++)
    {
        int pos=vv[i].ss;
        int mx=(a[pos]-1)/2;
        while (p+1<i&&vv[p+1].ff<=mx)
        {
            p++;
            update(1,1,n,vv[p].ss,1);
        }
        int t=get(1,1,n,pos);
        if (t==-1) t=get(1,1,n,1);
        nx[pos]=t;
    }
    int pos=0,mx=-1;
    for (int i=1; i<=n; i++)
    if (a[i]>mx) {mx=a[i]; pos=i;}
    if (nx[pos]==-1)
    {
        for (int i=1; i<=n; i++)
            cout<<-1<<" ";
            cout<<"\n";
            return 0;
    }
    if (nx[pos]>pos) dp[pos]=nx[pos]-pos; else
    dp[pos]=nx[pos]+n-pos;
    for (int j=pos-1; j>=1; j--)
    {
        dp[j]=dp[j+1]+1;
        int kol=nx[j]-j;
        if (nx[j]==-1) continue;
        if (nx[j]<=j) kol=nx[j]+n-j;
        dp[j]=min(dp[j],kol);
    }
    dp[n+1]=dp[1];
    for (int j=n; j>pos; j--)
    {
        dp[j]=dp[j+1]+1;
        int kol=nx[j]-j;
        if (nx[j]==-1) continue;
        if (nx[j]<=j) kol=nx[j]+n-j;
        dp[j]=min(dp[j],kol);
    }
    for (int i=1; i<=n; i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
}