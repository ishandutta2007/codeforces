#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool hole[2000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int x;
        cin>>x;
        hole[x]=1;
    }
    int cur=1;
    if (hole[1]){cout<<1<<endl;return 0;}
    while(k--){
        int u,v;
        cin>>u>>v;
        if (cur==u) cur=v;
        else if (cur==v)cur=u;
        if (hole[cur]){cout<<cur<<endl;return 0;}
    }
    cout<<cur<<endl;
}