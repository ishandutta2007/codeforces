#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> mp;
map<int,int> id;
int dp[1000000];
int back[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ret=0;
    int pos;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (mp.find(x-1)!=mp.end())mp[x]=mp[x-1]+1;
        else mp[x]=1;
        dp[i]=mp[x];
        id[x]=i;
        if (mp[x]==1)back[i]=-1;
        else back[i]=id[x-1];
        if (mp[x]>ret)ret=mp[x],pos=i;
    }
    vector<int> vec;
    while(pos!=-1)vec.push_back(pos),pos=back[pos];
    reverse(vec.begin(),vec.end());
    cout<<ret<<endl;
    for (auto x:vec)cout<<x<<' ';
}