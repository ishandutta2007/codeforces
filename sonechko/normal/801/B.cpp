#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    string d="";
    for (int i=0; i<s.size(); i++)
    if (s[i]<t[i]) {cout<<"-1"<<endl; return 0;} else d+=t[i];
    cout<<d<<endl;
}