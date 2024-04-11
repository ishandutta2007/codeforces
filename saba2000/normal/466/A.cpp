#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int n,m,a,b,d1,d2,d3,d4;
cin>>n>>m>>a>>b;
d1=n*a;
d2=(n/m)*b+(n%m)*a;
d3=((n+m-1)/m)*b;
d4=d1; 
//cout<<d1<<" "<<d2<<" "<<d3<<" "<<endl;
if (d4>d2) d4=d2;
if (d4>d3) d4=d3;
cout<<d4<<endl;
//system ("pause");
return 0;
}