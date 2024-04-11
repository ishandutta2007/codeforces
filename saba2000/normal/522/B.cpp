#include <iostream>
#include <vector>
using namespace std;
int main ()
{ int n,w1,h1,maxh=0,max2h=0,sumw=0,ch,cw;
cin>>n;
vector <int> w,h;
for (int i=0; i<n; i++)
{cin>>w1>>h1;
w.push_back(w1);
h.push_back(h1);
if (h1>maxh) { max2h=maxh; maxh=h1;}
else if (h1>max2h) max2h=h1;
sumw+=w1;
}
for (int i=0; i<n; i++)
{ch=maxh; cw=sumw;
if (h[i]==maxh) ch=max2h;
cw-=w[i];
cout<<cw*ch<<" ";
}
cout<<endl;
//system ("pause");
return 0;
}