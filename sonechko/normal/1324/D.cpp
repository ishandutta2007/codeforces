#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;


int a[N],b[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<pair<int,int> > vs;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        vs.pb(mp(a[i]-b[i],i));
    }
    sort(vs.begin(),vs.end());
    multiset<int> st;
    int k=0;
    ll ans=0;
    for (int i=0; i<vs.size(); i++)
    {
        while (st.size()>0&&(*st.begin())<vs[i].ff)
        {
            int x=(*st.begin());
            st.erase(st.find(x));
            k++;
        }
        ans+=1ll*k;
        int pos=vs[i].ss;
        st.insert(b[pos]-a[pos]);
    }
    cout<<ans;
}