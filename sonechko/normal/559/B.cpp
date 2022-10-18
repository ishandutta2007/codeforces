#include<bits/stdc++.h>
using namespace std;
bool good(string s, string t)
{
    if (s==t) return true;
    if (s.size()%2==1) return false;
    string p="",d="";
    for (int i=0; i<s.size(); i++)
        if (i<s.size()/2) p+=s[i]; else d+=s[i];
    string pp="",dd="";
    for (int i=0; i<t.size(); i++)
        if (i<t.size()/2) pp+=t[i]; else dd+=t[i];
    if (good(p,dd)&&good(d,pp)) return true;
    if (good(p,pp)&&good(d,dd)) return true;
    return false;
}
int main()
{
    string s,t;
    cin>>s>>t;
    if (good(s,t)) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}