#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

vector<int> v[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    set<int> st;
    use[1]=1;
    for (int j=0; j<v[1].size(); j++)
        if (use[v[1][j]]==0) st.insert(v[1][j]);
    cout<<1<<" ";
    for (int i=2; i<=n; i++)
    {
        int p=*st.begin();
        st.erase(p);
        use[p]=1;
        cout<<p<<" ";
        for (int j=0; j<v[p].size(); j++)
            if (use[v[p][j]]==0) st.insert(v[p][j]);
    }
    cout<<endl;
}