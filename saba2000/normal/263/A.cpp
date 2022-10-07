#include <iostream>
using namespace std;
int main ()
{int a[25]={4,3,2,3,4,3,2,1,2,3,2,1,0,1,2,3,2,1,2,3,4,3,2,3,4},j,o;
for (int i=0; i<25; i++)
{cin>>o;
if (o==1) j=i;
}
cout<<a[j]<<endl;
//system ("pause");
return 0;
}