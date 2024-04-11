#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,x;
 cin>>n>>x;
 int m=0,t=1,l,u;
for(int i=0;i<n;i++){
   cin>>l>>u;
   m+=u-l+(l-t)%x+1;
   t=u+1;
}
cout<<m<<endl;return 0;}