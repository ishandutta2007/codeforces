#include <iostream>
using namespace std;
char a[4]={'a','a','b','b'};
int n;
main()
{cin>>n;
while(n--)
cout<<a[n%4];}