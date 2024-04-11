//program 91C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Parent[100000];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<N;i++)Parent[i]=i;
  int Ans=1;
  while(M--)
    {
      int X,Y;cin>>X>>Y;X=Root(X-1);Y=Root(Y-1);
      if(X==Y)Ans=Ans*2%1000000009;else Parent[X]=Y;
      cout<<Ans-1<<endl;
    }
  return 0;
}