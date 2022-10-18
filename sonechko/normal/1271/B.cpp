#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void try_(string s, char c)
{
    s="."+s;
    int n=s.size()-1;
    vector<int> vv;
    for (int i=1; i<=n; i++)
        if (s[i]!=c)
    {
        if (i==n) return;
        s[i]=c;
        if (s[i+1]=='B') s[i+1]='W'; else s[i+1]='B';
        vv.pb(i);
    }
    cout<<vv.size()<<"\n";
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
    cout<<"\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    try_(s,'W');
    try_(s,'B');
    cout<<-1;
}