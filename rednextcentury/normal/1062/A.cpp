#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    a[0]=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[++n]=1001;
    n++;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (a[j]-a[i]==j-i)
                ret=max(ret,j-i-1);
        }
    }
    cout<<ret<<endl;
}