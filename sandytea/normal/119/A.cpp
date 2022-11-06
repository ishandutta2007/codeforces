//program 119A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int GCD(int X,int Y)
{
  return Y?GCD(Y,X%Y):X;
}

int main()
{
  int A,B,N;cin>>A>>B>>N;
  bool Flag=true;
  while(N>=GCD(N,A)){Flag=!Flag;N-=GCD(N,A);int Tmp=A;A=B;B=Tmp;}
  cout<<Flag<<endl;
  return 0;
}