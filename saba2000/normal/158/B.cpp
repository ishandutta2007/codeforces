#include <iostream>
#include <vector>
using namespace std;
int main()
{ vector <int> h,a1,a2,a3,a4;
int n,a=0,x,b,c=0,b1,b2;
cin>>n;
while (a<n)
{cin>>x;
h.push_back (x); a++;}
a=0;
while (a<n)
{if (h[a]==1) a1.push_back(h[a]);
if (h[a]==2) a2.push_back(h[a]);
if (h[a]==3) a3.push_back(h[a]);
if (h[a]==4) a4.push_back(h[a]);
a++;
}
b1=a1.size();
b2=a2.size();
c=c+a4.size()+a3.size()+(b2/2);
b1=b1-a3.size();
b2=b2%2;
if (b2<=0) c=c+b2;
else 
{if (b2=0) c=c+b1;
else
{c=c+1; b1=b1-2;}}
if (b1>0) c=c+((b1+3)/4);
cout<<c;
return 0;
}