#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{ int a,b,c,d,pM,pV;
cin>>a>>b>>c>>d;
pM=max((a*3)/10,a-(a/250)*c);
pV=max((b*3)/10,b-(b/250)*d);
if (pM>pV) cout<<"Misha"<<endl;
if (pM<pV) cout<<"Vasya"<<endl;
if (pM==pV) cout<<"Tie"<<endl;
//system ("pause");
return 0;
}