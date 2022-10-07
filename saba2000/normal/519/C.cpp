#include <iostream>
using namespace std;
int main ()
{int n,m,p=0;
cin>>n>>m;
while (n!=0 && m!=0 && n+m>2)
{n--; m--;
if (n>m) n--; else m--;
p++;
}
cout<<p<<endl;
return 0;
}