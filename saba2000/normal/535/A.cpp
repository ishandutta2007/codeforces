#include <iostream>
#include <string>
using namespace std;
int main ()
{string a[20]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string b[9]={"","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int n;
cin>>n;
if (n==0) cout<<"zero"<<endl; else
if (n<20) cout<<a[n]<<endl; else
{cout<<b[n/10-1];
if (n%10!=0) cout<<"-"<<a[n%10]<<endl;}
//system ("pause");
return 0;
}