#include <iostream>
using namespace std;
long long p=1000000007,n,ans1=1,ans2=1;
int main ()
{cin>>n;
for (int i=0; i<n; i++)
{ans1*=27;
ans1=ans1%p;
}
for (int i=0; i<n; i++)
{ans2*=7;
ans2=ans2%p;}
cout<<(p+ans1-ans2)%p<<endl;
return 0;
}