//program 93A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M,L,R;cin>>N>>M>>L>>R;L--;R--;
  int X1=L/M,Y1=L%M,X2=R/M,Y2=R%M;
  if(X1==X2||M==1||(Y1==0&&Y2==M-1)||(Y1==0&&R==N-1))cout<<1<<endl;
  else if(Y1==0||Y2==M-1||Y1==Y2+1||X1+1==X2||R==N-1)cout<<2<<endl;
  else cout<<3<<endl;
  return 0;
}