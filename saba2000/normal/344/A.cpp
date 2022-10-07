#include <string>
#include <iostream>
using namespace std;
int main ()
{int n, k=1;
string a,b;
cin>>n;
cin>>a; b=a;
for (int i=0; i<n-1; i++)
{cin>>a;
if (a!=b) k++;
b=a;
}
cout<<k<<endl;
//system ("pause");
return 0;
}