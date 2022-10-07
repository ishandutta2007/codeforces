#include <iostream>
using namespace std;
int main ()
{
long long int n,v;
cin>>n;
if (n%2==1) v=0-((n+1)/2);
if (n%2==0) v=n/2;
cout<<v;
return 0;
}