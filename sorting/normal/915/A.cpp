#include<iostream>
#include<algorithm>

using namespace std;

int a[1001];

int main  ()
{
   int n,k,i;

   cin>>n>>k;

   for(i=0;i<n;i++)cin>>a[i];

   sort(a,a+n);

   for(i=n-1;i>=0;i--)
   {
        if(k%a[i]==0)
        {
            cout<<k/a[i]<<endl;
            return 0;
        }
   }

   cout<<n-i<<endl;

   return 0;
}