#include <bits/stdc++.h>
using namespace std;
long long a[100000];
bool vis[1000000];
int main ()
{
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int num=n;
    int ret=0;
    while(num)
    {
        bool ok=0;
        for (int i=1;i<=n;i++)
        {
            if (vis[i])continue;
            if (k*2>=a[i])
                k=max(a[i],k),vis[i]=1,num--,ok=1;
        }
        if (!ok)k=k*2,ret++;
    }
    cout<<ret<<endl;
}