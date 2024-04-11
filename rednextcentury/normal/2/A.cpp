#include<bits/stdc++.h>
#define ll long long
using namespace std;
string S[1000000];
int F[1000000];
map<string,int> mp;
map<string,int> ok;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>S[i]>>F[i];
        mp[S[i]]+=F[i];
    }
    int mx=-1;
    int num=0;
    for (auto p:mp)
    {
        if (p.second>mx)mx=p.second,num=1;
        else if (p.second==mx)num++;
    }
    if (num==1)
    {
        for (auto p:mp)
        {
            if (p.second==mx)
            {
                cout<<p.first<<endl;return 0;
            }
        }
    }
    else
    {
        for (auto p:mp)
        {
            if (p.second==mx)
            {
                ok[p.first]=1;
            }
        }
    }
    mp.clear();
    for (int i=0;i<n;i++)
    {
        mp[S[i]]+=F[i];
        if (mp[S[i]]>=mx && ok[S[i]])
        {
            cout<<S[i]<<endl;
            return 0;
        }
    }
}