#include <iostream>
using namespace std;
char a[8][8];
int nw,nb,mc,mcb,mw=8,mb=-1,mcw;
int main ()
{for (int i=0; i<8; i++)
 for (int j=0; j<8; j++)
 cin>>a[i][j];
 
 for (int i=0; i<8; i++)
 {nw=0; nb=0; mcb=0; mcw=0;
 for (int j=0; j<8; j++)
 {if (a[j][i]=='W') {nw++; if (nw==1 && nb==0) mcw=j; else nw=1; mcb=0;}
 if (a[j][i]=='B') {nb++; mcb=j;}}
 if (mcb!=0) mb=max(mb,mcb);
 if (mcw!=0) mw=min(mw,mcw);
}
//cout<<mb<<" "<<mw<<endl;
if (7-mb<mw) cout<<'B'<<endl;
else cout<<'A'<<endl;
}