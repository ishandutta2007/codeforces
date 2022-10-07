#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main ()
{int a,b,c;
string s[7]={"0/1","1/6","1/3","1/2","2/3","5/6","1/1"};
cin>>a>>b;
c=7-max(a,b);
cout<<s[c]<<endl;
//system ("pause");
return 0;
}