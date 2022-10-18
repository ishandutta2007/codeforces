#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans=0;
    for (int i=0; i<s.size(); i++)
    if (s[i]==t[i]) {} else
    if (i+1<s.size()&&s[i]==t[i+1]&&t[i]==s[i+1]) {swap(s[i],s[i+1]); ans++;} else
    {
        ans++;
    }
    cout<<ans<<"\n";
}