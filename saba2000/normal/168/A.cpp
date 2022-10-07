#include <iostream>
using namespace std;
int main ()
{int n,x,y,a;
cin>>n>>x>>y; a=(n*y+99)/100;
if (a<=x)  cout<<0<<endl;
else cout<<a-x<<endl;
return 0;
}