#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int a,b,m,r=0,x,y;
    int k;
    cin>>a>>b;
    if (a==b) cout<<"infinity"<<endl; 
    else {
    a=a-b;
    m=0;
    for(int i=1; i<=(int)sqrt((double)a); i++) {
   if (a%i==0) {x=i; y=a/i;
   if (x==y) {if (x>b) m++; } else
   { if (x>b)
   m++;
   if (y>b)
   m++;
}
}
}
cout<<m<<endl;
}
return 0;
}