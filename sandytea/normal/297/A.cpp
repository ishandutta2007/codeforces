//program 297-A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Get()
{
  char c;
  while(c=getchar(),c<'0'||c>'9');
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return X;
}

void Output(int X)
{
  int Len=0,Data[10];
  while(X)
    {
      Data[Len++]=X%10;
      X/=10;
    }
  if(!Len)
    Data[Len++]=0;
  while(Len--)
    putchar(Data[Len]+48);
  putchar('\n');
}

int main()
{
  string A,B;
  cin>>A>>B;
  int M=0,N=0;
  for(int i=0;i<A.size();i++)
    if(A[i]=='1')
      M++;
  for(int i=0;i<B.size();i++)
    if(B[i]=='1')
      N++;
  if(N>(M+1)/2*2)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}