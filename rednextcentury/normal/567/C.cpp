# include <iostream>
# include <algorithm>
# include <map>
# include <stdio.h>
using namespace std;
map<int,long long> dp0;
map<int,long long> dp1;
long long a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]%k!=0)
        {
            dp0[a[i]]++;
            continue;
        }
        int x=a[i]/k;
        ans+=dp1[x];
        dp1[a[i]]+=dp0[x];
        dp0[a[i]]++;
    }
    cout<<ans<<endl;
}