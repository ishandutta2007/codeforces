#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{string s; long long int k,an=0,l=0,an2=0;
vector <long long int> v;
cin>>k>>s;
v.push_back(-1);
for (int i=0; i<s.length(); i++)
if (s[i]=='1') {v.push_back(i); an2+=l*(l+1)/2; l=0;} else
if (s[i]=='0') l++; 
v.push_back(s.length());
an2+=l*(l+1)/2; 
int z=v.size()-k;
for (int i=1; i<z; i++)
{
an+=(v[i+k]-v[i+k-1])*(v[i]-v[i-1]);
}
if (k==0)cout<<an2<<endl; else
cout<<an<<endl;
return 0;
}