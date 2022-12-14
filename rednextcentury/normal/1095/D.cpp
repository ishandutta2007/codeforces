#include<bits/stdc++.h>
using namespace std;
map<int,int> mp[1000000];
int a[1000000][3];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2];
        mp[i][a[i][1]]=1;
        mp[i][a[i][2]]=1;
    }
    for (int i=1;i<=n;i++)
    {
        int x = a[i][1], y = a[i][2];
        if (mp[y][x]==1)
            swap(a[i][1],a[i][2]);
    }
    vector<int> vec;
    vec.push_back(1);
    int cur=1;
    while(1)
    {
        int x = a[cur][1], y=a[cur][2];
        vec.push_back(x);
        if (vec.size()==n)break;
        vec.push_back(y);
        if (vec.size()==n)break;
        cur=y;
    }

    for (auto x:vec)cout<<x<<' ';
}