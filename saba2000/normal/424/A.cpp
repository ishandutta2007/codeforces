#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main ()
{int n,s=0,l=0,k;
string a;
 cin>>n>>a;
for (int i=0; i<a.length(); i++)
if (a[i]=='x') s++;else l++;
k=abs(l-s)/2; cout<<k<<endl;
for (int i=0; i<a.length(); i++)
if (l>s && a[i]=='X' && k>0) {cout<<'x'; k--;}
else if (s>l && a[i]=='x' && k>0) {cout<<'X';k--;}
else cout<<a[i];
return 0;
}