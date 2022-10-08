#include<bits/stdc++.h>
using namespace std;
int k;
int a[100009];
int dp11[100009],dp12[100009],dp21[100009],dp22[100009];
main()
{int n;;
cin>>n;
for (int i=1; i<=n; i++)
    cin>>a[i];
dp11[n]=a[n]; dp12[n]=0;
dp22[n]=a[n]; dp21[n]=0;
int S=a[n];
for (int i=n-1; i>=0; i--)
{
    S+=a[i];
    dp11[i]=-1;
    int s=0;
    for (int j=i; j<=n; j++)
    {
        if(dp21[j+1]+a[j]>dp11[i])
            dp11[i]=dp21[j+1]+a[j];
    }
    dp12[i]=S-dp11[i];
     dp22[i]=-1;
    s=0;
    for (int j=i; j<=n; j++)
    {
        if(dp12[j+1]+a[j]>dp22[i])
            dp22[i]=dp12[j+1]+a[j];
    }
    dp21[i]=S-dp22[i];
}
cout<<dp12[1]<<" "<<dp11[1]<<endl;
}