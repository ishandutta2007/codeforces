#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ull unsigned long long
#define mp make_pair
#define pb push_back



const int N = 4e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
ll a[N],an[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll sum=0,ans=0;
    set<pair<ll,ll> > st;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
    {
        sum+=a[i];
        ans+=a[i]*(m-i);
        st.insert(mp(a[i],i));
    }
    ll d=m;
    for (int i=1; i<=n; i++)
    {
        d++;
        ans+=sum;
        if (d<=n)
        {
            st.insert(mp(a[d],d));
            sum+=a[d];
        }
        pair<ll,ll> p=*st.rbegin();
        st.erase(p);
        sum-=p.ff;
        an[p.ss]=i+m;
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        cout<<an[i]<<" ";
    cout<<endl;
}