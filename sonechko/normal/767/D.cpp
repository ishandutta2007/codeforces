#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ld long double
int a[N],n,m,k;
pair<int,int> b[N];
bool good(int l)
{
    vector<int> v;
    int a1=1,b1=m-l+1;
    while (1==1)
    {
        if (a1==n+1&&b1==m+1) break;
        if (a1==n+1) {v.pb(b[b1].ff); b1++;} else
        if (b1==m+1) {v.pb(a[a1]); a1++;} else
        if (b[b1].ff<a[a1]) {v.pb(b[b1].ff); b1++;} else
            {v.pb(a[a1]); a1++;}
    }
    int l1=0;
    for (int i=0; i<=v.size(); i++)
    {
        if (v[l1]<i) return 0;
        for (int j=1; j<=k; j++)
        {
            l1++;
            if (l1==v.size()) return 1;
        }
    }
    return 0;
}
int main()
{
    sync;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
        {
            cin>>b[i].ff;
            b[i].ss=i;
        }
    sort(b+1,b+m+1);
    int l=0,r=m;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    int ans=0;
    if (good(r)) ans=r; else
    if (good(l)) ans=l; else {cout<<-1<<endl; return 0;}
    cout<<ans<<endl;
    for (int i=m-ans+1; i<=m; i++)
        cout<<b[i].ss<<" ";
    cout<<endl;
}