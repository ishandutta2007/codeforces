#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{int n,k,a,b,s[100000],o[100000];
cin>>a>>b>>n>>k;
for (int i=0; i<a; i++)
cin>>s[i];
for (int i=0; i<b; i++)
cin>>o[i];
if (s[n-1]<o[b-k]) cout<<"YES"<<endl; else cout<<"NO"<<endl;
return 0;
}