#include <iostream>
using namespace std;
int main ()
{int n;
cin>>n; n=-n;
if (n>0) if (n%10>n/10%10) n=n/10; else n=(n-((n/10%10)*10)+(n%10)*10)/10;
cout<<-n<<endl;
//system ("pause");
return 0;
}