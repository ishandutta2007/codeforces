#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;
int kol[N],use[N];
vector<int> v[N];
void dfs(int l)
{
    use[l]=1;
    int kk=0;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]!=5) kk++;
    if (kk!=2) {cout<<"NO"<<endl; exit(0);}
    for (int i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==0) dfs(v[l][i]);
}
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
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        kol[i]=v[i].size();
        if (kol[i]==1) vv.pb(i);
    }
    for (int ii=0; ii<vv.size(); ii++)
    {
        int l=vv[ii];
        use[l]=5;
        for (int i=0; i<v[l].size(); i++)
        {
            kol[v[l][i]]--;
            if (kol[v[l][i]]==1) vv.pb(v[l][i]);
        }
    }
    int kk=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0) kk++;
    if (kk<3) {cout<<"NO"<<endl; return 0;}
    for (int i=1; i<=n; i++)
    if (use[i]==0)
    {
        dfs(i);
        break;
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) {cout<<"NO"<<endl; return 0;}
    cout<<"FHTAGN!"<<endl;
}

/**
 
6 6
6 3
6 4
5 1
2 5
1 4
5 4
 
FHTAGN!
 
6 5
5 6
4 6
3 1
5 1
1 2
 
NO
**/