//program 117A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

int main()
{
  int N=GetNumber(),M=GetNumber(),Cycle=M*2-2;
  for(int i=0;i<N;i++)
    {
      int S=GetNumber(),T=GetNumber(),Time=GetNumber(),Ans;
      if(S==T)
        Ans=Time;
      else if(S<T)
        {
          int First=Time/Cycle*Cycle+S-1;
          while(First<Time)First+=Cycle;
          Ans=First+T-S;
        }
      else if(S>T)
        {
          int First=Time/Cycle*Cycle-(S-1);
          while(First<Time)First+=Cycle;
          Ans=First+S-T;
        }
      cout<<Ans<<endl;
    }
  return 0;
}