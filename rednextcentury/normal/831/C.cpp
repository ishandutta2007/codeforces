#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll b[1000000];
ll org[1000000];
map<int,int> mp;
set<int> possible;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i], org[i] = a[i], a[i]+=a[i-1];
    for (int i=1;i<=m;i++)cin>>b[i], mp[b[i]]++;
    for (int i=1;i<=n;i++){
        ll start = b[1] - a[i];
        map<int,int> pp;
        for (int i=1;i<=n;i++){
            start+=org[i];
            pp[start]++;
        }

        bool ok=1;
        for (auto p:mp){
            if (p.second > pp[p.first])ok=0;
        }
        if (ok)possible.insert(start);
    }
    cout<<possible.size()<<endl;
}