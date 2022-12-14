#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool is[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        if (is[i])continue;
        ret++;
        for (int j=i;j<=n;j++)
        {
            if (a[j]%a[i]==0)is[j]=1;
        }
    }
    cout<<ret<<endl;
}