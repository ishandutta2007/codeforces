# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <set>
# include <map>
using namespace std;
map<int,int> mp;
set<int> tocheck;
int a[1000000][2];
    int n;
    int mid;
int check(int v)
{
    int t1=0;
    for (int i=0;i<n;i++)
    {
        if (a[i][0]==v)
            t1++;
    }
    return max(mid-t1,0);
}
int main()
{
    cin>>n;
    if (n%2==0)
        mid=n/2;
    else
        mid=n/2+1;
    for (int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        if (a[i][0]==a[i][1])
        {
            ++mp[a[i][0]];
        }
        else
        {
            ++mp[a[i][0]];
            ++mp[a[i][1]];
        }
        if (mp[a[i][0]]>=mid)
            tocheck.insert(a[i][0]);
        if (mp[a[i][1]]>=mid)
            tocheck.insert(a[i][1]);
    }
    int ans=100000000;
    for (set<int>::iterator it=tocheck.begin();it!=tocheck.end();it++)
    {
        ans=min(ans,check(*it));
    }
    if (ans>n)
        cout<<-1<<endl;
    else
    cout<<ans<<endl;
}