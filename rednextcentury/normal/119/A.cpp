# include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
    if (a==0)return b;
    if (b==0)return a;
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
int main ()
{
   int a[2],b,n;
   cin>>a[0]>>a[1]>>n;
   int p;
   bool t=0;
   while(1)
   {
       p=GCD(a[t],n);
       n-=p;
       t=!t;
       if (n==0)
        break;
   }
   cout<<!t<<endl;
}