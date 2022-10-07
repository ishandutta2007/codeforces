#include<bits/stdc++.h>
using namespace std;
pair<int,int> c[523];
int a[42],b[40];
main()

{
   int n;
   cin>>n;

   for (int i=0; i<n; i++)
    {cin>>a[i];
   c[i]={a[i],i};}
   sort(c,c+n);
   for (int i=0; i<n; i++)
    b[(c[(i+1)%n].second)]=c[i].first;
   for(int i=0; i<n; i++)

    cout<<b[i]<<" ";
   cout<<endl;
   return 0;
}
//a[2]-a[1] a[3]-a[2]... a[n]-a[n-1], a[1]-a[n];
//x1 x1 ... xn,  -(x1+...xn)