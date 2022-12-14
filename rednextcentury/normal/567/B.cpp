# include <iostream>
# include <algorithm>
# include <ios>
# include <stdio.h>
using namespace std;
bool typ[1000000];
int a[1000000];
bool vis[1000000];
int main()
{
    int n;
    cin>>n;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        if (x=='+')
        {
            typ[i]=1;
            cin>>a[i];
            vis[a[i]]=1;
        }
        else
        {
            typ[i]=0;
            cin>>a[i];
            if (!vis[a[i]])
                ret++;
            vis[a[i]]=1;
        }
    }
    int ans=ret;
    for (int i=0;i<n;i++)
    {
        if (typ[i])
            ret++;
        else
            ret--;
        ans=max(ans,ret);
    }
    cout<<ans<<endl;
}