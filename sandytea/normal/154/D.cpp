//program 154D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int X1,X2,A,B;cin>>X1>>X2>>A>>B;
  if(A<=0&&B>=0)
    if(X1+A<=X2&&X2<=X1+B)
      cout<<"FIRST"<<endl<<X2<<endl;
    else
      cout<<"DRAW"<<endl;
  if(A>0)
    {
      int Delta=X2-X1;
      if(Delta<A)
        cout<<"DRAW"<<endl;
      else if(Delta%(A+B)==0)
        cout<<"SECOND"<<endl;
      else if(A<=Delta%(A+B)&&Delta%(A+B)<=B)
        cout<<"FIRST"<<endl<<X1+Delta%(A+B)<<endl;
      else cout<<"DRAW"<<endl;
    }
  if(B<0)
    {
      int Delta=X1-X2,Tmp=-A;A=-B;B=Tmp;
      if(Delta<A)
        cout<<"DRAW"<<endl;
      else if(Delta%(A+B)==0)
        cout<<"SECOND"<<endl;
      else if(A<=Delta%(A+B)&&Delta%(A+B)<=B)
        cout<<"FIRST"<<endl<<X1-Delta%(A+B)<<endl;
      else cout<<"DRAW"<<endl;
    }
  return 0;
}