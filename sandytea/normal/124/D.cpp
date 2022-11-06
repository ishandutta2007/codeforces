//program 124D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int A,B,X1,Y1,X2,Y2;
  cin>>A>>B>>X1>>Y1>>X2>>Y2;A*=2;B*=2;
  int P1=(X1+Y1)/A;if(X1+Y1<0)P1--;
  int Q1=(X1-Y1)/B;if(X1-Y1<0)Q1--;
  int P2=(X2+Y2)/A;if(X2+Y2<0)P2--;
  int Q2=(X2-Y2)/B;if(X2-Y2<0)Q2--;
  int X=max(P1,P2)-min(P1,P2),Y=max(Q1,Q2)-min(Q1,Q2);
  cout<<max(X,Y)<<endl;
  return 0;
}