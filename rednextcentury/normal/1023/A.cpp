#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x;
    cin>>x>>x;
    string s,t;
    cin>>s>>t;
    int pos=-1;
    for (int i=0;i<s.size();i++)
        if (s[i]=='*')pos=i;
    if (pos==-1 && s==t)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if (t.size()+1<s.size())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if (pos==-1 && s!=t)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int m=t.size();
    int p = s.size();
    p-=pos;
    p--;
    if (m-p<0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if (s.substr(0,pos)==t.substr(0,pos) && s.substr(pos+1,s.size())==t.substr(m-p,t.size()))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}