#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
     {
     int n;
     int a[300007];
     int i;
     long long br=0;
     scanf("%d",&n);
     for(i=0;i<n;i++)
          {
          scanf("%d",&a[i]);
          }
     sort(a,a+n);
     for(i=0;i<n;i++)
          {
          br+=abs((i+1)-a[i]);
          }
     printf("%I64d\n",br);
     return 0;
     }