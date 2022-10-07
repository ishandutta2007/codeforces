#include <iostream>
#include <cmath>
using namespace std;
int main ()
{long long int r,x,y,x1,y1,l;
cin>>r>>x>>y>>x1>>y1;
l=int((sqrt((double)(abs(x1-x)*abs(x1-x)+abs(y1-y)*abs(y1-y)))/(2*r))); 
if ((sqrt((double)(abs(x1-x)*abs(x1-x)+abs(y1-y)*abs(y1-y)))/(2*r))>double(l)) l++;
cout<<l<<endl;
return 0;
}