#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
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
set<pair<ll,ll> > u, p, up;
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif // LOCAL
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    for (int i=1; i<=n; i++)
    {
        ll a;
        cin>>a;
        string s;
        cin>>s;
        if (s[0]=='U') u.insert(mp(a,i));
        else p.insert(mp(a,i));
        up.insert(mp(a,i));
    }
    ll ans1=0,ans2=0;
    for (int i=1; i<=a; i++)
    {
        if (u.size()==0) break;
        ans1++;
        pair<ll,ll> pp=*u.begin();
        u.erase(pp);
        up.erase(pp);
        ans2+=pp.ff;
    }
    for (int i=1; i<=b; i++)
    {
        if (p.size()==0) break;
        ans1++;
        pair<ll,ll> pp=*p.begin();
        p.erase(pp);
        up.erase(pp);
        ans2+=pp.ff;
    }
    for (int i=1; i<=c; i++)
    {
        if (up.size()==0) break;
        ans1++;
        pair<ll,ll> pp=*up.begin();
        up.erase(pp);
        ans2+=pp.ff;
    }
    cout<<ans1<<" "<<ans2<<endl;
}