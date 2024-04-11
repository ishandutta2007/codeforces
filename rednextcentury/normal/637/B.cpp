#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string s[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for (int i=n-1;i>=0;i--)
    {
        if (++mp[s[i]]==1)
            cout<<s[i]<<'\n';
    }
}