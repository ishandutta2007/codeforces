#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 11;

string m(string s, string t)
{
    for (int d=0; d<min(s.size(),t.size()); d++)
        if (s[d]<t[d]) return s; else
        if (t[d]<s[d]) return t;
    if (s.size()<t.size()) return s;
    return t;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    string s,t;
    cin>>s>>t;
    string res=s+t;
    for (int p=0; p<s.size(); p++)
    for (int d=0; d<t.size(); d++)
    {
        string g="";
        for (int j=0; j<=p; j++)
            g+=s[j];
        for (int j=0; j<=d; j++)
            g+=t[j];
        res=m(res,g);
    }
    cout<<res<<endl;
}