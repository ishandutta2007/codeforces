#include <iostream>
using namespace std;
int main ()
{int a,b,c,d,k=0;
cin>>a>>b>>c>>d;
if (a==b || a==c || a==d) k++;
if (b==c || b==d) k++;
if (c==d) k++;
cout<<k<<endl;
//system ("pause");
return 0;
}