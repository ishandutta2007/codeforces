#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
int main ()
{string c;
int n,t;
cin>>n>>t;
cin>>c;
for (int i=0; i<t; i++)
for (int j=0; j<n-1; j++)
if (c[j]=='B' && c[j+1]=='G') {swap(c[j],c[j+1]); j++;}

cout<<c<<endl;
return 0;
}