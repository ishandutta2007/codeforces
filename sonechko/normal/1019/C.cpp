#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e6 + 11;

vector<int> v[N],vv[N];
int kol[N],use[N];

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
    }
    vector<int> vs,ans;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        use[i]=1;
        vs.pb(i);
        for (int j=0; j<v[i].size(); j++)
            use[v[i][j]]=1;
    }
    for (int i=vs.size()-1; i>=0; i--)
    {
        int l=vs[i];
        if (use[l]==1)
        {
            ans.pb(l);
            for (int j=0; j<v[l].size(); j++)
                use[v[l][j]]=2;
        }
    }
    cout<<ans.size()<<"\n";
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

/**

1 2
2 3
2 4
2 5

**/