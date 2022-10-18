#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 1e6 + 11;
const int P = 31;
const int MOD = 1e9 + 7;

int d1[N],d2[N];
ll h1[N],h2[N];
ll st[N];
int n;

inline ll get1(int l, int r)
{
    ll hh1=(h1[r]-h1[l-1]+MOD)%MOD;
    hh1=(hh1*1ll*st[n-r])%MOD;
    return hh1;
}

inline ll get2(int l, int r)
{
    ll hh1=(h2[l]-h2[r+1]+MOD)%MOD;
    hh1=(hh1*1ll*st[l-1])%MOD;
    return hh1;
}

inline bool good(int l, int r)
{
    return (l>r||get1(l,r)==get2(l,r));
}

void up()
{
    string s;
    cin>>s;
    s="."+s;
    n=s.size()-1;
    int l=1,r=n,k=0;
    while (l<r&&s[l]==s[r])
    {
        k++;
        l++;
        r--;
    }
    st[0]=1;
    for (int i=1; i<=n; i++)
    {
        st[i]=(st[i-1]*1ll*P)%MOD;
    }
    for (int i=1; i<=n; i++)
    {
        h1[i]=(h1[i-1]+(s[i]-'a'+1)*1ll*st[i])%MOD;
    }
    h2[n+1]=0;
    for (int i=n; i>=1; i--)
    {
        h2[i]=(h2[i+1]+(s[i]-'a'+1)*1ll*st[n-i+1])%MOD;
    }
    for (int i=1; i<=n; i++)
    {
        d1[i]=0;
        int l=1,r=min(i,n-i+1);
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(i-mid+1,i+mid-1)) l=mid; else r=mid;
        }
        if (good(i-r+1,i+r-1)) d1[i]=r; else d1[i]=l;


        l=0;
        r=min(i,n-i);
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(i-mid+1,i+mid)) l=mid; else r=mid;
        }
        if (good(i-r+1,i+r)) d2[i]=r; else d2[i]=l;
    }
    int ans=0,l1=0,r1=0;
    for (int i=1; i<=n; i++)
    {
        int p=d1[i];
        int lp1=i-p+1,rp1=i+p-1;
        if (lp1-1<n-rp1)
        {
            if (lp1<=k+1)
            {
                int t1=i-p;
            if (ans<t1*2+p+p-1)
            {
                ans=t1*2+p+p-1;
                l1=t1+p+p-1;
                r1=t1;
            }
            }
        } else
        {
            if (rp1>=n-k)
            {
                int t2=n-(i+p)+1;
            if (ans<t2*2+p+p-1)
            {
                ans=t2*2+p+p-1;
                l1=t2;
                r1=t2+p+p-1;
            }
            }
        }
        p=d2[i];
        lp1=i-p+1;
        rp1=i+p;
        if (lp1-1<n-rp1&&d2[i]!=0)
        {
            int t1=i-p;
            if (lp1<=k+1)
            {
            if (ans<t1*2+p+p)
            {
                ans=t1*2+p+p;
                l1=t1+p+p;
                r1=t1;
            }
            }
        } else
        if (d2[i]!=0)
        {
            if (rp1>=n-k)
            {
                int t2=n-(i+p+1)+1;
            if (ans<t2*2+p+p)
            {
                ans=t2*2+p+p;
                l1=t2;
                r1=t2+p+p;
            }
            }
        }
    }

    for (int i=1; i<=l1; i++)
        cout<<s[i];
    for (int i=n-r1+1; i<=n; i++)
        cout<<s[i];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}