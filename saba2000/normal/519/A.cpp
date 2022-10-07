#include <iostream>
using namespace std;
int main ()
{char p[5]={'q','r','b','n','p'},p1[5]={'Q','R','B','N','P'},u;
int l[5]={9,5,3,3,1},b=0,w=0;
for (int i=0; i<64; i++)
{cin>>u;
 for (int j=0; j<5; j++)
 if (u==p[j]) b+=l[j]; else if (u==p1[j]) w+=l[j];
}
if (w>b) cout<<"White"<<endl; else if (w==b) cout<<"Draw"<<endl; else cout<<"Black"<<endl;
//system ("pause");
return 0;
}