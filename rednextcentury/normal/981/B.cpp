#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    long long ret=0;
    int n,m;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if (b > mp[a])
            ret = ret - mp[a] + b, mp[a] = b;
    }
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if (b > mp[a])
            ret = ret - mp[a] + b, mp[a] = b;
    }
    cout<<ret<<endl;
}