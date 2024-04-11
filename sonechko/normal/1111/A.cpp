#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

bool gl(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    if (s.size()!=t.size()) return cout<<"NO", 0;
    int k1=0,k2=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]!=t[i])
        {
            int c1=0,c2=0;
            if (gl(s[i])) c1=1;
            if (gl(t[i])) c2=1;
            if (c1!=c2) return cout<<"NO", 0;
        }
    cout<<"YES";
}