#include <bits/stdc++.h>
using namespace std;
bool vis[2000000];
int p[2000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i];
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            int v = i;
            int ret=-1;
            while(!vis[v])
            {
                vis[v]=1;
                v=p[v];
                ret++;
            }
            ans+=ret;
        }
    }
    if (ans%2!=n%2)
        cout<<"Um_nik"<<endl;
    else cout<<"Petr"<<endl;
}