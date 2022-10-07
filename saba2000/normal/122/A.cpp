#include <iostream>
using namespace std;
int main ()
{ int a[14]={4,7,44,47,77,74,444,474,744,447,477,747,774,777};
int k,t=0;
cin>>k;
for (int i=0; i<14; i++)
if (k%a[i]==0) {t=1; cout<<"YES"; break;}
if (t==0) cout<<"NO"<<endl;
return 0;
}