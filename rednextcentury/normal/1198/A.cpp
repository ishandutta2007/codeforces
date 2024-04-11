#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int sum[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,I;
    cin>>n>>I;
    I=I*8;
    I/=n;
    if (I>30)I=1e9;
    else I=(1<<I);
    if (I>n)I=n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<pair<int,int> > vec;
    vec.push_back({0,0});
    for (auto p:mp)vec.push_back(p);
    int ret=0;
    for (int i=1;i<vec.size();i++)
    {
        sum[i]=sum[i-1];
        sum[i]+=vec[i].second;
        int p = i-I;
        if (p<0)p=0;
        ret=max(ret,sum[i]-sum[p]);
    }
    cout<<n-ret<<endl;

}