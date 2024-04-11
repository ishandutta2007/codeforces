#include <iostream>
using namespace std;
int main ()
{int a,m;
cin>>a>>m;
while (m%2==0) m=m/2;
if (a%m==0) cout<<"Yes"<<endl; else cout<<"No"<<endl;
return 0;
}