# include <iostream>
# include <string>
using namespace std;
int dp1[1000000];
int dp2[1000000];
int a[1000000];
int n;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int now=1;
    for (int i=1;i<n;i++)
    {
        if (a[i]>a[i-1])
        {
            now++;
        }
        else
            now=1;
        dp1[i]=now;
    }
    now=1;
    for (int i=n-1;i>=0;i--)
    {
        if (a[i]<a[i+1])
            now++;
        else
            now=1;
        dp2[i]=now;
    }
    int ans=0;
    dp1[0]=dp2[0]=dp1[n]=dp2[n]=1;
    for (int i=0;i<n;i++)
    {
        if (i==0)
        {
         //   if (a[i+1]>a[i])
            ans=max(ans,dp2[i+1]);
        }
        else if (i==n-1)
        {
          //  if (a[i]>a[i-1])
            ans=max(ans,dp1[i-1]);
        }
        else
        {
            if (a[i+1]-a[i-1]>1)
            ans=max(ans,dp1[i-1]+dp2[i+1]);
           // if (a[i+1]>a[i])
            ans=max(ans,dp2[i+1]);
          //  if (a[i]>a[i-1])
            ans=max(ans,dp1[i-1]);
        }
    }
    if (n==1)
    cout<<1<<endl;
    else
    cout<<ans+1<<endl;
}