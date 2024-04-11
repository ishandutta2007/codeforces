#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

int pr[N],res[N],pp[N];
vector<int> v[N],anss;
int deep[N],maxdeep[N];

void dfs(int l)
{
    maxdeep[l]=0;
    for (int j=0; j<v[l].size(); j++)
    {
        dfs(v[l][j]);
        maxdeep[l]=max(maxdeep[l],maxdeep[v[l][j]]+1);
    }
    ///cout<<l<<": "<<maxdeep[l]<<endl;
}

int rec(int l)
{
    //cout<<"so get "<<l<<endl;
    while (pr[l]!=pp[l])
    {
        anss.pb(l);
        pp[l]=pp[pp[l]];
    }
    vector<pair<int,int> > vv;
    for (int j=0; j<v[l].size(); j++)
        vv.pb(mp(maxdeep[v[l][j]],v[l][j]));
    sort(vv.begin(),vv.end());
    int last=l;
    for (int j=0; j<vv.size(); j++)
    {
        //cout<<l<<" -> "<<vv[j].ss<<endl;
        //cout<<"res "<<vv[j].ss<<" = "<<last<<endl;
        res[vv[j].ss]=last;
        pp[vv[j].ss]=last;
        last=rec(vv[j].ss);
        ///cout<<"new last = "<<last<<endl;
    }
    ///cout<<"get out from "<<l<<endl;
    return last;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    pr[0]=-1;
    for (int i=1; i<n; i++)
    {
        int l;
        cin>>l;
        pr[i]=l;
        v[l].pb(i);
    }
    dfs(0);
    res[0]=-1;
    pp[0]=-1;
    int cc=rec(0);
    vector<int> ress;
    while (cc>-1)
    {
        ress.pb(cc);
        cc=res[cc];
    }
    for (int j=ress.size()-1; j>=0; j--)
        cout<<ress[j]<<" ";
    cout<<endl;
    cout<<anss.size()<<"\n";
    for (int j=0; j<anss.size(); j++)
        cout<<anss[j]<<" ";
    cout<<endl;
}
/**
11
0 0 2 0 4 3 2 4 8 9
**/