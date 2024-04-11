#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int P1 = 31;
const int P2 = 29;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

vector<int> v[N],s[N];
int ss[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
    }
    for (int i=1; i<=m; i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        for (int j=1; j<v[i].size(); j++)
            v[i][j]=v[i][j-1]+v[i][j];
    }
    set<int> st;
    for (int i=1; i<=m; i++)
        st.insert(i);
    vector<int> vv;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int sum=0;
        vv.clear();
        for (auto it=st.begin(); it!=st.end(); it++)
        {
            int p=*it;
            if (v[p].size()<i) vv.pb(p); else
            if (v[p][i-1]>0) sum+=v[p][i-1];
        }
        ans=max(ans,sum);
        for (int j=0; j<vv.size(); j++)
            st.erase(vv[j]);
    }
    cout<<ans<<endl;
}