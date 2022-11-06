//program 160B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int GetNumber()
{
  char c=getchar();
  while(c<'0'||c>'9')c=getchar();
  return c-48;
}

int main()
{
  int N,A[100],B[100];;cin>>N;
  for(int i=0;i<N;i++)A[i]=GetNumber();
  for(int i=0;i<N;i++)B[i]=GetNumber();
  sort(A,A+N);sort(B,B+N);
  bool Ans=true,Flag;
  if(A[0]==B[0])Ans=false;else Flag=(A[0]>B[0]);
  for(int i=1;Ans&&i<N;i++)
    if(A[i]==B[i])
      Ans=false;
    else
      if(Flag^(A[i]>B[i]))
        Ans=false;
  cout<<(Ans?"YES":"NO")<<endl;
  return 0;
}