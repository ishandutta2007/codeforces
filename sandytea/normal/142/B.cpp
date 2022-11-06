//program 142B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Calc(int X,int Y)
{
  if(X==1)return Y;
  if(X==2)
    {
      if(Y%4==0)return Y;
      if(Y%4==1)return Y+1;
      if(Y%4==2)return Y+2;
      if(Y%4==3)return Y+1;
    }
  return (X*Y+1)/2;
}

int main()
{
  int M,N;cin>>M>>N;
  cout<<Calc(min(M,N),max(M,N))<<endl;
  return 0;
};