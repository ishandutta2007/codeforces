#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

ll d[N],ans;
vector<int> v[N];
int last;

void dfs(int l, int pr)
{
    d[l]=l;
    if (pr>0) d[l]=min(d[l],d[pr]);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    ans=2e9;
    int p,x;
    cin>>p>>x;
    x=((x+last)%n) + 1;
    dfs(x,0);
    for (int i=2; i<=q; i++)
    {
        int t,x;
        cin>>t>>x;
        x=((x+last)%n)+1;
        ///cout<<"!! "<<t<<" "<<x<<endl;
        if (t==1) ans=min(ans,d[x]); else
        {
            last=min(ans,d[x]);
            cout<<last<<"\n";
        }
    }
}