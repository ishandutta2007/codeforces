#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
int a[N][27],dp1[N],dp2[N],n,m,b[N][27];
string s,t;
int next(int l, int k)
{
    if (l>n) return -1;
    int l1=l,r1=n;
    while (r1-l1>1)
    {
        int mid=(l1+r1)/2;
        if (a[mid][k]-a[l-1][k]>0) r1=mid; else l1=mid;
    }
    if (a[l1][k]-a[l-1][k]>0) return l1;
    if (a[r1][k]-a[l-1][k]>0) return r1;
    return -1;
}
int pref(int r, int k)
{
    if (r<1) return -1;
    int l1=1,r1=r;
    while (r1-l1>1)
    {
        int mid=(l1+r1)/2;
        if (a[r][k]-a[mid-1][k]>0) l1=mid; else r1=mid;
    }
    if (a[r][k]-a[r1-1][k]>0) return r1;
    if (a[r][k]-a[l1-1][k]>0) return l1;
    return -1;
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif // LOCAL
    cin>>s>>t;
    n=s.size();
    m=t.size();
    s='1'+s;
    t='1'+t;
    for (int i=1; i<=n; i++)
        for (int j=0; j<26; j++)
        if (s[i]-'a'==j) a[i][j]=a[i-1][j]+1; else a[i][j]=a[i-1][j];
    for (int i=n; i>=1; i--)
        for (int j=0; j<26; j++)
        if (s[i]-'a'==j) b[i][j]=b[i+1][j]+1; else b[i][j]=b[i+1][j];
    dp1[n]=0;
    for (int i=1; i<=m; i++)
    {
        int os=dp1[i-1];
        int k=next(os+1,t[i]-'a');
        dp1[i]=k;
        if (os==-1) dp1[i]=-1;
    }
    int kk=m+1;
    dp2[m+1]=n+1;
    for (int i=m; i>=1; i--)
    {
        int os=dp2[i+1];
        int k=pref(os-1,t[i]-'a');
        dp2[i]=k;
        if (os==-1) dp2[i]=-1;
    }
    int l=0,r=m+1;
    for (int i=1; i<m; i++)
        if (dp1[i]!=-1)
        {
            int l1=i+1,r1=m;
            while (r1-l1>1)
            {
                int mid=(l1+r1)/2;
                if (dp2[mid]>dp1[i]) r1=mid; else l1=mid;
            }
            if (dp2[l1]>dp1[i]) r1=l1;
            if (dp2[r1]>dp1[i])
            {
                if (i+m-r1+1>l+m-r+1)
                {
                    l=i;
                    r=r1;
                }
            }

        }
    for (int i=1; i<=m; i++)
    {
        if (dp1[i]!=-1&&i>l+m-r+1) {l=i; r=m+1;}
        if (dp2[i]!=-1&&m-i+1>l+m-r+1) {l=0; r=i;}
    }
    string st="";
    for (int i=1; i<=l; i++)
        st+=t[i];
    for (int i=r; i<=m; i++)
        st+=t[i];
    if (st=="") cout<<"-"<<endl; else cout<<st<<endl;
}