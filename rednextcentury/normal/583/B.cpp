# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <map>
using namespace std;
int a[1000000];
bool vis[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int num=0;
    int cur=0;
    int ans=-1;
    while(num<n)
    {
        ans++;
        int i;
        if (ans%2)
            i=n-1;
        else
            i=0;
        while(i>=0 && i<n)
        {
            if (!vis[i] && a[i]<=cur)
                cur++,vis[i]=1,num++;
            if (ans%2)
                i--;
            else
                i++;
        }
    }
    cout<<ans<<endl;
}