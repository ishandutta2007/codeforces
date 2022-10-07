#include<iostream>
using namespace std;
int main ()
{
int a,b,n,r;
cin>>a>>b>>n;
r=a;
for (int j=0; j<10; j++)
if ((a*10+j)%b==0) {a=a*10+j; break;}
if (a==r) cout<<-1<<endl;
else {cout<<a;
for (int i=0; i<n-1; i++)
cout<<0;
}
cout<<endl;
return 0;
}