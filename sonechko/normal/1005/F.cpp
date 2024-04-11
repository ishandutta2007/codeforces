#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;

vector<int> v[N],w[N],t[N];
bool use[N];
int dist[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        w[l].pb(i);
        v[r].pb(l);
        w[r].pb(i);
    }
    vector<int> vv;
    vv.pb(1);
    dist[1]=0;
    use[1]=1;
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j];
        for (int i=0; i<v[l].size(); i++)
            if (use[v[l][i]]==0)
        {
            use[v[l][i]]=1;
            dist[v[l][i]]=dist[l]+1;
            vv.pb(v[l][i]);
        }
    }
    string s="";
    for (int i=1; i<=m; i++)
        s+="0";
    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            if (dist[v[i][j]]==dist[i]-1) t[i].pb(w[i][j]-1);
        //cout<<i<<": ";
        //for (int j=0; j<t[i].size(); j++)
        //    cout<<t[i][j]<<" ";
        //cout<<endl;
        s[t[i][0]]='1';
    }
    vector<string> vs;
    for (int ii=1; ii<=k; ii++)
    {
        vs.pb(s);
        int c=0;
        for (int i=n; i>=2; i--)

            if (s[t[i].back()]=='0'&&t[i].size()>1)
        {
            int p=0;
            for (int j=0; j<t[i].size(); j++)
            if (s[t[i][j]]=='1') p=j;
            s[t[i][p]]='0';
            p++;
            s[t[i][p]]='1';
            c=1;
            break;
        } else
        {
            int p=0;
            for (int j=0; j<t[i].size(); j++)
            if (s[t[i][j]]=='1') p=j;
            s[t[i][p]]='0';
            s[t[i][0]]='1';
        }

        if (c==0) break;
    }
    cout<<vs.size()<<"\n";
    for (int j=0; j<vs.size(); j++)
        cout<<vs[j]<<"\n";
}