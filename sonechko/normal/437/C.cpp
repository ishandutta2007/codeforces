#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 1000 + 11;
int a[N],use[N];
pair<int,int> aa[N];
vector<int> v[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            aa[i].ss=i;
        }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        aa[l].ff+=a[r];
        aa[r].ff+=a[l];
    }
    set<pair<int,int> > st;
    for (int i=1; i<=n; i++)
    {
        st.insert(mp(a[i],i));
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        pair<int,int> p=*st.rbegin();
        st.erase(p);
        ans+=(ll)aa[p.ss].ff;
        int l=p.ss;
        use[l]=1;
        for (int j=0; j<v[l].size(); j++)
            if (use[v[l][j]]==0)
            {
                aa[v[l][j]].ff-=a[l];
            }
    }
    cout<<ans<<endl;
}