#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    int n;
    cin>>n;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ret=max(ret,++mp[x]);
    }
    cout<<ret<<endl;
}