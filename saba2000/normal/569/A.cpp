#include <iostream>
using namespace std;
int ans,T;
double V1,S,q;
int main ()
{cin>>T>>S>>q;
V1=1-(q-1)/q; 
while (S+0.000001<T)
{
S=S/V1;
ans++;}
cout<<ans<<endl;

}