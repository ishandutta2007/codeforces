#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    s='.'+s;
    t='.'+t;
    int ans=n;
    vector<int> v,w;
    v.clear();
   for (int i=1; i<=n; i++)
        v.pb(i);
    for (int i=1; i<=m-n+1; i++)
    {
        int kol=0;
        w.clear();
        for (int j=1; j<=n; j++)
            if (t[i+j-1]!=s[j]) {w.pb(j); kol++;}
        if (kol<ans) {ans=kol; v=w;}
    }
    cout<<ans<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}