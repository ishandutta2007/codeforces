#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define mp make_pair
const ll N = 100000 + 11;

map<string,string> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s,t;
        cin>>s>>t;
        mt[t]=s;
    }
    for (int i=1; i<=m; i++)
    {
        string s,t;
        cin>>s>>t;
        string d="";
        for (int i=0; i<t.size()-1; i++)
            d+=t[i];
        cout<<s<<" "<<t<<" "<<"#"<<mt[d]<<"\n";
    }
}