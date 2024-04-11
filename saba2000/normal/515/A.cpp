#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
int a,b,s;
cin>>a>>b>>s;
if (s<abs(a)+abs(b)) cout<<"no"<<endl;
else if ((abs(a)+abs(b))%2==s%2) cout<<"yes"<<endl;
else cout<<"no"<<endl;
//system ("pause");
return 0;
}