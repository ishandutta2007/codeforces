#include <iostream>
#include<cmath>
using namespace std; 
int main ()
{long long n;
cin>>n;
for (long long i=2; i<=(int)sqrt((double)n); i++)
while(n%(i*i)==0)
n/=i;
cout<<n;
}