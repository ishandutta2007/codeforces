#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int a[5009],f[5009];
int m[5009][5009];
main()
{
    int n;
    cin>>n;
    int k=0,x=0,z;
    for (int i=0; i<n; i++)
        {cin>>a[i];
        k=gcd(k,a[i]);
        if(a[i]==1) x++;
       }
       if(k!=1){cout<<-1<<endl; return 0;}
       if(x>0) {cout<<n-x<<endl; return 0;}
   for (int i=0; i<n; i++)
   {

       m[i][i]=a[i];
       for (int j=i+1; j<n; j++)
         m[i][j]=gcd(m[i][j-1],a[j]);
   }
   for (int i=0;  i<n; i++)
   {
       f[i]=1000000;
       for (int p=i; p<n; p++)
       {
           if(gcd(m[i][p],m[0][i])!=1) continue;
           int l=0,r=i;
           while(l<r)
           {
               int mid=(l+r+1)/2;
               if(gcd(m[mid][i],m[i][p])==1) l=mid;
               else r=mid-1;
           }
           f[i]=min(f[i],p-l);
       }
       //cout<<f[i]<<endl;
   }
   int ans=5*n;
   for (int i=0; i<n; i++)
    ans=min(ans,f[i]+n-1);
   cout<<ans<<endl;
}