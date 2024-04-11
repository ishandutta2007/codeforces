#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for (int j=0;j<=31;j++)
        {
            if (mp.find((1<<j)-a[i])!=mp.end())
                ans+=mp[(1<<j)-a[i]];
        }
        mp[a[i]]++;
    }
    cout<<ans<<endl;
}