#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 1e6 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    int ps1=0,ps2=0;
    for (int i=1; i<=n; i++)
    {
        string t;
        cin>>t;
        if (t==s) {cout<<"YES"<<endl; return 0;}
        if (t[0]==s[1]) ps1=1;
        if (t[1]==s[0]) ps2=1;
    }
    if (ps1==1&&ps2==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}