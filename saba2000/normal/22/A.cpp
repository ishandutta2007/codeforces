#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{int k[109],p[209]={0},s=0;
int n; cin>>n;
for (int i=0; i<n; i++)
{int q;cin>>q; if (p[q+100]==0) {k[s]=q; s++;} p[q+100]=1;}
sort(k,k+s);
if (s<2) cout<<"NO"<<endl; else
cout<<k[1]; 
return 0;
}