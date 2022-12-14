#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ret=0;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i+2<=n;i++)
    {
        if (a[i]+a[i+1]+a[i+2]==2 && a[i+1]==0)
            a[i+2]=0,ret++;
    }
    cout<<ret<<endl;
}