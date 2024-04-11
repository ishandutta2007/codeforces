#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    s="."+s;
    t="."+t;
    int ans=0;
    if (n%2==1&&s[(n+1)/2]!=t[(n+1)/2]) ans++;
    for (int i=1; i<=n/2; i++)
    {
        vector<char> v;
        v.pb(s[i]);
        v.pb(s[n-i+1]);
        v.pb(t[i]);
        v.pb(t[n-i+1]);
        if (v[0]==v[2]&&v[1]==v[3]) {} else
        if (v[0]==v[3]&&v[1]==v[2]) {} else
        if (v[0]==v[1]&&v[2]==v[3]) {} else
        if (v[0]==v[3]||v[0]==v[2]||v[1]==v[2]||v[1]==v[3]||
            v[2]==v[3]) {ans++;}
        else {ans+=2;}
    }
    cout<<ans;
}