#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1e6 + 11;

vector<int> v1[10],v2[10];

void up()
{
    int n;
    cin>>n;
    for (int i=0; i<=9; i++)
    {
        v1[i].clear();
        v2[i].clear();
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=7; j>=0; j--)
            if ((i-1)&(1<<j)) v2[j].pb(i); else v1[j].pb(i);
    }
    int ans=0;
    for (int i=0; i<=6; i++)
    {
        if (v1[i].size()==0||v2[i].size()==0) continue;
        cout<<v1[i].size()<<" "<<v2[i].size()<<" ";
        for (int j=0; j<v1[i].size(); j++)
            cout<<v1[i][j]<<" ";
        for (int j=0; j<v2[i].size(); j++)
            cout<<v2[i][j]<<" ";
        cout<<endl;
        int x;
        cin>>x;
        ans=max(ans,x);
    }
    cout<<"-1 "<<ans<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    up();
}