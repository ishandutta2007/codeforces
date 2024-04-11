#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long a[4006][4006];
long long sol(int n)
{
   a[0][0]=1;
   for (int i=1;i<=n;i++)
   {
      a[i][0]=a[i-1][i-1];
      for (int j=1;j<=i;j++)
         a[i][j]=(a[i][j-1]+a[i-1][j-1])%mod;
   }
}
int main ()
{
    int n;
    cin>>n;
    sol(n+1);
    cout<<(a[n+1][0]-a[n][0]+mod)%mod<<endl;
}