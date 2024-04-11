# include <iostream>
using namespace std;
int main()
{
long t;
cin>>t;
for( int i=0;i<t;i++)
{
long long n;
cin>>n;
if (n%2==0)
cout<<4*n+1<<endl;
else
{
if((n+1)%4!=0)
cout<<2*n+1<<endl;
else
cout<<n+1<<endl;
}
}
}