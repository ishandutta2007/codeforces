#include <iostream>
using namespace std;
int main ()
{
    int a,r=0;
    cin>>a;
    int m=1;
    while (a>0)
    {
    r++;
    a=a-m;
    m=m+r+1;
     
}
if (a<0)
cout<<r-1<<endl; else cout<<r<<endl;
return 0;
}