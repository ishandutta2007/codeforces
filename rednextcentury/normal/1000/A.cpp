#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    int ret=0;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if (mp[s]==0)
            ret++;
        else
            mp[s]--;
    }
    cout<<ret<<endl;
}