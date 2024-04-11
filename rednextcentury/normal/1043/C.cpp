#include<bits/stdc++.h>
using namespace std;
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='a' && i+1==s.size())
            ret[i]=1;
        else if (s[i]=='b' && i+1==s.size())
            ret[i]=0;
        else
        {
            if (s[i]!=s[i+1])
                ret[i]=1;
            else ret[i]=0;
        }
    }
    for (int i=0;i<s.size();i++)
        cout<<ret[i]<<' ';
}