#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 3e5 + 11;

vector<pair<int,ll> > v[N];
ll a[N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        ll k;
        cin>>l>>r>>k;
        k*=2;
        v[l].pb(mp(r,k));
        v[r].pb(mp(l,k));
    }
    set<pair<ll,int> > st;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert(mp(a[i],i));
    }
    for (int ppp=1; ppp<=n; ppp++)
    {
        pair<ll,int> p=*st.begin();
        st.erase(p);
        int l=p.ss;
        for (int j=0; j<v[l].size(); j++)
        {
            int to=v[l][j].ff;
            if (a[to]>a[l]+v[l][j].ss)
            {
                st.erase(mp(a[to],to));
                a[to]=a[l]+v[l][j].ss;
                st.insert(mp(a[to],to));
            }
        }
    }
    for (int p=1; p<=n; p++)
        cout<<a[p]<<" ";
    cout<<endl;
}