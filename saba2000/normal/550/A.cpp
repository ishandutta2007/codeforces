#include <string>
#include <iostream>
using namespace std;
int main ()
{string s; int G=0,AB=0,BA=0,k[100009]={0};
cin>>s;
for (int i=0; i<s.length(); i++)
if (s.substr(i,2)=="AB") {AB++; if (k[i-1]==1) G++; k[i]++;}  else
if (s.substr(i,2)=="BA") {BA++; if (k[i-1]==1) G++; k[i]++;}  
if ((AB+BA-G>1 || G>2) && AB>0 && BA>0) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}