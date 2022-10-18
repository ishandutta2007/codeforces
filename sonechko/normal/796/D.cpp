#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 3e5 + 11;


int use[N],uses[N];
vector<int> v[N],w[N],q;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        q.pb(l);
        use[l]=1;
    }
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        w[l].pb(i);
        w[r].pb(i);
    }
    for (int j=0; j<q.size(); j++)
    {
        int l=q[j];
        for (int i=0; i<v[l].size(); i++)
            if (use[v[l][i]]==0)
        {
            q.pb(v[l][i]);
            use[v[l][i]]=1;
            uses[w[l][i]]=1;
        }
    }
    int p=0;
    for (int i=1; i<n; i++)
        if (uses[i]==0) p++;
    cout<<p<<endl;
    for (int i=1; i<n; i++)
        if (uses[i]==0) cout<<i<<" ";
    cout<<endl;
}