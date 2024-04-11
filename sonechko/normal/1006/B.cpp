#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

pair<int,int> a[N];

int main()
{
    #ifndef __WIN32
    ///freopen("abc.in", "r", stdin);
    ///freopen("abc.out", "w", stdout);
    #endif // __WIN32
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    int ans=0;
    vector<int> vv;
    vv.pb(0);
    for (int i=n-k+1; i<=n; i++)
       {
           ans+=a[i].ff;
           //cout<<a[i].ff<<" "<<a[i].ss<<endl;
           vv.pb(a[i].ss);
       }
    cout<<ans<<endl;
    sort(vv.begin(),vv.end());
    vv.back()=n;
    for (int i=1; i<=k; i++)
        cout<<vv[i]-vv[i-1]<<" ";
    cout<<endl;
}