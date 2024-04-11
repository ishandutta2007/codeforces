#include<bits/stdc++.h>
using namespace std;

#define ff first
#define pb push_back
#define ss second

const int N = 2e5 + 11;

map<string,int> mt1,mt2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        mt1[s]++;
    }
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        mt2[s]++;
    }
    vector<string> v;
    v.pb("XXXS");
    v.pb("XXXL");
    v.pb("XXS");
    v.pb("XXL");
    v.pb("XS");
    v.pb("XL");
    v.pb("S");
    v.pb("M");
    v.pb("L");
    int ans=0;
    for (int j=0; j<v.size(); j++)
    {
        int l=min(mt1[v[j]],mt2[v[j]]);
        mt1[v[j]]-=l;
        mt2[v[j]]-=l;
        ans+=mt1[v[j]];
    }
    cout<<ans<<endl;
}