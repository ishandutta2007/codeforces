#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 3e5 + 11;

int l[N],r[N],res[N];

void ks()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>l[i]>>r[i];
    for (int i=1; i<=n; i++)
    {
        res[i]=0;
    }
    vector<int> vv;
    int ps=0;
    for (int j=1; j<=5000; j++)
    {
        for (int i=1; i<=n; i++)
        if (l[i]==j) vv.pb(i);
        while (ps<vv.size())
        {
            int d=vv[ps];
            if (r[d]<j) {ps++;} else break;
        }
        if (ps<vv.size()) {res[vv[ps]]=j; ps++;}
    }
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int p=1; p<=t; p++)
        ks();
}