#include <iostream>
using namespace std;
int main ()
{long long int l,r;
cin>>l>>r;
if (r-l<2+l%2) cout<<-1<<endl; else
cout<<l+l%2<<" "<<l+l%2+1<<" "<<l+l%2+2<<endl;
return 0;
}