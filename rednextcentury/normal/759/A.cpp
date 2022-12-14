#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> vec[1000000];
int a[1000000];
int b[1000000];
bool vis[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    int num=0;
    int odd=0;
    for (int i=1;i<=n;i++)
    {
        if (b[i]==1)
            odd++;
        if (!vis[i])
        {
            num++;
            int v=i;
            while(!vis[v])
                vis[v]=1,v=a[v];
        }
    }
    odd%=2;
    int ans=(num);
if (num==1)ans=0;
    if (!odd)ans++;
    cout<<ans<<endl;
}