#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
long long i,l,b,c,t,h;
string e,r;
cin>>e>>r;
i=e[0]-96;
l=r[0]-96;
b=e[1]; c=r[1];
if ((i-l)*(i-l)>=(b-c)*(b-c))h=sqrt((i-l)*(i-l));
else h=sqrt((b-c)*(b-c));
cout<<h<<endl;
for (t=0;b!=c||i!=l;t++) {
if (i>l) {i=i-1;cout<<"L";}
else if (i<l){i=i+1;cout<<"R";}
if (b>c) {b=b-1;cout<<"D";}
else if (b<c){b=b+1;cout<<"U";}
cout<<endl;
}
}