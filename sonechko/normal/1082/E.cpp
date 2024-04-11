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

vector<int> v[N];
int a[N],s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,c;
    cin>>n>>c;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1];
        if (a[i]==c) s[i]++;
        v[a[i]].pb(i);
    }
    int ans=s[n];
    for (int i=1; i<=500000; i++)
    {
        int mx=-2e9;
        for (int j=0; j<v[i].size(); j++)
        {
            mx=max(mx,s[v[i][j]-1]-j);
            ans=max(ans,s[n]+j-s[v[i][j]]+1+mx);
        }
    }
    cout<<ans<<endl;
}


/**
l r
pref[l-1]==c
+
max_kol_rav[l..r]
+
pref[n]-pref[r]

max_kol_rav[l..r]-ss[l.rr]

l1 l2 l3 l4 l5 l6 l7
r-l+1-ss[r]+ss[l-1]
r-ss[r]+1
+ ss[l-1]-l

**/