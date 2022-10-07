#include <iostream>
using namespace std;
int main ()
{ int n,ev,pat=0,uc=0;
cin>>n;
for (int i=0; i<n; i++) {
    cin>>ev;
    if (ev==-1 && pat==0) uc++;
    else pat+=ev;
}
cout<<uc<<endl;
//system ("pause");
return 0;
}