#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main ()
{ string s;
double r2,r3,r4,g1;  int m,mo; cin>>s;
if (s.length()==1) m=(s[s.length()-1]-48); else
 m=(s[s.length()-1]-48)+(s[s.length()-2]-48)*10;
mo=m%4; if (mo==0) mo==4;
g1=mo;
r2=(int)(pow(2,g1))%5;
r3=(int)pow(3,g1)%5;
r4=(int)pow(4,g1)%5;
cout<<(int)(1+r2+r3+r4)%5<<endl;
//system ("pause");
return 0;
}