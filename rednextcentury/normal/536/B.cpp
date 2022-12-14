# include <iostream>
# include <vector>
# include <cstring>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
#define MOD 1000000007
string f;
string p;
long long b[2000001];
bool can[2000001];
bool a[3000000];
long long m,n;
void pre()
{
    long long i=0,j=-1;
    b[i]=j;
    while(i<m)
    {
        while(j>=0 && (f[i]!=f[j] && f[i]!='?' && f[j]!='?'))
        {
            j=b[j];
        }
        i++;
        j++;
        b[i]=j;
    }
}
void KMP()
{
    long long i=0,j=0;
    while(i<n)
    {
        while(j>=0 && (p[j]!=f[i] && f[i]!='?'))
        {
            j=b[j];
        }
        i++;j++;
        if (j==m)
        {
            can[i-j]=1;
            j=b[j];
        }
    }
}
long long power(long long num,long long x)
{
    long long ret=1;
    while(x--)
    {
        ret*=num;
        ret%=MOD;
    }
    return ret;
}
int main()
{
   long long l,k;
   cin>>l>>k;
   cin>>p;
   f=p;
   m=p.length();
   for (long long i=0;i<m;i++)
   {
       f+="?";
   }
   n=f.length();
   pre();
   KMP();
   for (long long i=0;i<k;i++)
   {
       long long x;
       cin>>x;
       a[x-1]=1;
   }
   long long last=-1;
   long long num=0;
   for (long long i=0;i<l;i++)
   {
       if (a[i]==1)
       {
           if (last>=i)
           {
               if (!can[m-(last-i)-1])
               {
                   cout<<0<<endl;
                   return 0;
               }
           }
           last=i+m-1;
       }
       if (i>last)
        num++;
   }
   cout<<power(26,num)<<endl;

}