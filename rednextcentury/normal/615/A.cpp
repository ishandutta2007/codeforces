#include <bits/stdc++.h>

using namespace std;
bool vis[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int c;
            cin>>c;
            vis[c]=1;
        }
    }
    for (int i=1;i<=m;i++)
    {
        if (!vis[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}