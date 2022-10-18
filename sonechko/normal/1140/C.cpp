#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 4e5 + 11;

pair<ll,ll> a[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ss>>a[i].ff;
    }
    sort(a+1,a+n+1);
    set<pair<ll,int> > st;
    ll sum=0,ans=0;
    for (int i=n; i>=1; i--)
    {
        st.insert(mp(a[i].ss,i));
        sum+=a[i].ss;
        if (st.size()>k)
        {
            pair<ll,int> p=*st.begin();
            st.erase(p);
            sum-=p.ff;
        }
        ans=max(ans,sum*a[i].ff);
    }
    cout<<ans<<endl;
}