# include <bits/stdc++.h>
using namespace std;
int main ()
{
   int n,m;
   cin>>n>>m;
   int d=1;
   while(n)
   {
       d++;
       n--;
       if (d%m==1)n++;
   }
   cout<<d-1<<endl;
}