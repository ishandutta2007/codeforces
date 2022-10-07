#include <iostream>
#include <string>
using namespace std;
int main()
{
int x=0,n,a=0;
string s;
cin>>n;
while (a<n)
{ cin>>s;
if (s=="X++") x++;
if (s=="++X") x++;
if (s=="X--") x--;
if (s=="--X") x--;
a++;
}
cout<<x<<endl;
return 0;
}