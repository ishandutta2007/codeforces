# include<iostream>
#include<bits/stdc++.h>
   using namespace std;
   int sum=0;
   int x[]={6,2,5,5,4,5,6,3,7,6};
   inline void calc(int h)
   {
       while(h)
       {
           sum+=x[h%10];
           h/=10;
       }
   }
int main()
{
    int a,b;
    cin>>a>>b;
    for (int i=a;i<=b;i++)
        calc(i);
    cout<<sum<<endl;
}