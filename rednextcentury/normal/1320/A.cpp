#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll best[1000000];
map<int,ll> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[i-x]+=x;
    }
    ll ret=0;
    for (auto p:mp)ret=max(ret,p.second);
    cout<<ret<<endl;
}