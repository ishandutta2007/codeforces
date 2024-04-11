#include <iostream>
using namespace std;
int main ()
{
    int n,x,a,b,o=1,r=0;
    cin>>n>>x;
    for (int i=0; i<n; i++) {
    cin>>a>>b;
    if ((a-o)%x==0) {r=r+b-a+1; o=b+1;} else
    if ((a-o)<x) {r=r+b-o+1; o=b+1;} else
    {r=r+(a-o)%x+b-a+1; o=b+1;}
}
cout<<r<<endl;
return 0;
}