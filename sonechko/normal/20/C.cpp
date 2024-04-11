#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e5 + 11;
ll dist[N],pred[N];
set<pair<ll,int> > st;
vector<int> v[N];
vector<ll> w[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        ll k;
        cin>>l>>r>>k;
        v[l].pb(r);
        w[l].pb(k);
        v[r].pb(l);
        w[r].pb(k);
    }
    st.insert(mp(0,1));
    dist[1]=0;
    for (int i=2; i<=n; i++)
    {
        st.insert(mp(1e18,i));
        dist[i]=1e18;
    }
    while (!st.empty())
    {
        pair<ll,int> p=*st.begin();
        st.erase(p);
        int l=p.ss;
        for (int i=0; i<v[l].size(); i++)
            if (dist[v[l][i]]>p.ff+w[l][i])
        {
            int to=v[l][i];
            pred[to]=l;
            st.erase(mp(dist[to],to));
            dist[to]=p.ff+w[l][i];
            st.insert(mp(dist[to],to));
        }
    }
    if (dist[n]==1e18) {cout<<"-1"<<endl; return 0;}
    vector<int> order;
    while (n!=0)
    {
        order.pb(n);
        n=pred[n];
    }
    for (int i=order.size()-1; i>=0; i--)
        cout<<order[i]<<" ";
    cout<<endl;
}