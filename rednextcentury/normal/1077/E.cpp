#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
vector<int> vec;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for (auto it:mp)
        vec.push_back(it.second);
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int ret=0;
    for (int i=1;i<=min((int)vec.size(),20);i++)
    {
        int mn=200000;
        int sum=0;
        for (int j=0;j<i;j++)
        {
            mn = min(mn,vec[j]/(1<<(i-j-1)));
            sum+=(1<<(i-j-1));
        }
        ret=max(ret,sum*mn);
    }
    cout<<ret<<endl;
}