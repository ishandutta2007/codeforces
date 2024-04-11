#include <iostream>
using namespace std;
int main ()
{
int a;
cin>>a;
int k[10]={2,7,2,3,3,4,2,5,1,2};
cout<<k[a/10]*k[a%10]<<endl;
return 0;
}