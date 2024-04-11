#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ret=0;
    for (int i=0;i+1<s.size();i++)
    {
        if (s[i]==t[i+1] && s[i+1]==t[i] && s[i]!=t[i] && s[i+1]!=t[i+1])
        {
            swap(s[i],s[i+1]);
            ret++;
        }
    }
    for (int i=0;i<s.size();i++)
        if (s[i]!=t[i])ret++;
    cout<<ret<<endl;
}