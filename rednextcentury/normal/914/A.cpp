#include <bits/stdc++.h>
using namespace std;
bool is[1000001];
int main()
{
    is[0]=1;
    for (int i=1;i<=1000;i++)
    {
        is[i*i]=1;
    }
    int n;
    cin>>n;
    int mx=-1000000000;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (x<0 || is[x]==0)mx=max(mx,x);
    }
    cout<<mx<<endl;
}