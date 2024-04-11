#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin>>n;
    cin>>s;
    bool ok=false;
    string ret="";
    for (int i=1;i<s.size();i++)
    {
        if (s[i]!=s[i-1])
            ret=s.substr(i-1,2),ok=1;
    }
    if (ok)cout<<"YES"<<endl<<ret<<endl;
    else cout<<"NO"<<endl;
}