#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    string t="";t+=s[0];
    for (int i=1;i<s.size();i++)
    {
        if (s[i]=='/' && s[i]==s[i-1])continue;
        t+=s[i];
    }
    while(t.size()>1 && t[t.size()-1]=='/')
        t.pop_back();

    cout<<t<<endl;
}