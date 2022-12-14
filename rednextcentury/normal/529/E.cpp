# include <iostream>
# include <vector>
# include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> best;
map<int,bool> mp;
int a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            if (mp[a[i]*j]==0)
            {
                mp[a[i]*j]=1;
                best[a[i]*j]=j;
            }
            else
                best[a[i]*j]=min(best[a[i]*j],j);
        }
    }
    mp[0]=1;
    int q;
    cin>>q;
    for (int o=0;o<q;o++)
    {
        int m;
        cin>>m;
        int mn=1000000;
        for (int i=1;i<=k;i++)
        {
            for (int j=0;j<n;j++)
            {
                int left=m-i*a[j];
                if (!mp[left])
                    continue;
                mn=min(i+best[left],mn);
            }
        }
        if (mn>k)
            cout<<-1<<endl;
        else
        cout<<mn<<endl;
    }
}