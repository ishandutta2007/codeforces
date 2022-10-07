#include <iostream>
#include <vector>
using namespace std;
int main()
{
vector <int> v;
int n,k,a=0,s,r,h=0;
cin>>n>>k;
while (a<n)
{cin>>r;
v.push_back(r);
if (a+1==k ) s=v[a];
a++;}
a=0;
while  (a<n)
{if (v[a]>=s && v[a]>0) h++;
a++;}
cout<<h;
return 0;
}