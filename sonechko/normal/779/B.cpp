#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int t;
    cin>>t;
    string p="";
    for (int i=s.size()-1; i>=0; i--)
        if (s[i]=='0') p=s[i]+p; else
        if ((int)p.size()>=t) p=s[i]+p;
    if (p[0]=='0') {cout<<s.size()-1<<endl; return 0;}
    cout<<s.size()-p.size()<<endl;
}