#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> v2[N],v1[N],vv1[N],vv2[N];
int a[N],b[N];
int d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v2[r].pb(l);
        vv2[r].pb(i);
        v1[l].pb(r);
        vv1[l].pb(i);
    }
    int mini=2e9;
    multiset<int> st;
    for (int i=1; i<=n; i++)
        st.insert(a[i]);
    int ans=0,p=0,pp=-1;
    for (int i=1; i<n; i++)
    {
        st.erase(st.find(a[i]));
        for (int j=0; j<v2[i].size(); j++)
        {
            for (int l=v2[i][j]; l<=i; l++)
            {
                b[l]--;
                if (b[l]<mini) mini=b[l];
            }
        }
        mini=min(mini,b[i]);
        int maxi=*st.rbegin();
        //cout<<i<<" - "<<mini<<" "<<maxi<<endl;
        if (maxi-mini>ans)
        {
            ans=maxi-mini;
            p=i;
            pp=0;
        }
    }
    st.clear();
    for (int i=1; i<=n; i++)
    {
        b[i]=a[i];
        st.insert(a[i]);
    }
    mini=2e9;
    for (int i=n; i>=2; i--)
    {
        st.erase(st.find(a[i]));
        for (int j=0; j<v1[i].size(); j++)
        {
            for (int l=i; l<=v1[i][j]; l++)
            {
                b[l]--;
                if (b[l]<mini) mini=b[l];
            }
        }
        mini=min(mini,b[i]);
        int maxi=*st.rbegin();
        if (maxi-mini>ans)
        {
            ans=maxi-mini;
            p=i;
            pp=1;
        }
    }
    cout<<ans<<endl;
    vector<int> vv;
    if (pp==0)
    {
        for (int i=1; i<=p; i++)
        for (int j=0; j<vv2[i].size(); j++)
        vv.pb(vv2[i][j]);
    } else
    if (pp==1)
    {
        for (int i=p; i<=n; i++)
        for (int j=0; j<vv1[i].size(); j++)
        vv.pb(vv1[i][j]);
    }
    cout<<vv.size()<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
    cout<<endl;
}