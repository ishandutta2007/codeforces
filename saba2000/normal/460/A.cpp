#include <iostream>
using namespace std;
int main ()
{
int n,m,s=0;
cin>>n>>m;
while (n!=0)
{n--;
if (s%m==0) n++;
s++;
}

cout<<s-1;
return 0;
}