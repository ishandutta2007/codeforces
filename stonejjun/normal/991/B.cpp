#include<bits/stdc++.h>
#define LL long long int
#define MOD 1000000007
using namespace std;
int main()
{
   int n, i, j, a, b, c,m,o=0,k,ans=0,arr[100];
   double wan;
   scanf("%d",&a);
   for(i=0;i<a;i++)
   {
   	scanf("%d",&arr[i]);
   	ans+=arr[i];
   }
   wan=4.5*a;
   sort(arr,arr+a);
   for(i=0;ans<wan;i++)
   {
   		ans=ans+5-arr[i];
   		o++;
   }
   
   printf("%d",o);
}