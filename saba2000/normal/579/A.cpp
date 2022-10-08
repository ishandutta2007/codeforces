#include <iostream>
using namespace std;
int x,a;
int main ()
{
cin>>x;
for (int i=x; i!=0; i/=2)
if (i%2==1) a++;
cout<<a<<endl;
}