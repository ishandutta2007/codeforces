#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main ()
{int k,l[256]={0},m[256]={0},n=0; 
string q;
cin>>k>>q;
for (int i=0; i<q.length(); i++)
if (l[q[i]]==0) { l[q[i]]=1; n++;}
if (n<k) cout<<"NO"<<endl; else
{cout<<"YES"<<endl; n=1; m[q[0]]=1;
for (int i=0; i<q.length(); i++)
{cout<<q[i];   if (m[q[i+1]]==0 && n<k) {cout<<endl; n++; m[q[i+1]]=1;} }
}
return 0;
}