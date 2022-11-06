//program 127D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

char S[1000000];
int Next[1000000];
bool Flag[1000000];

int main()
{
  int N=0;char c;
  while(c=getchar(),c>='a'&&c<='z')S[N++]=c;
  Next[0]=0;
  for(int i=1;i<N;i++)
    {
      int P=Next[i-1];
      while(P&&S[P]!=S[i])P=Next[P-1];
      if(S[P]==S[i])P++;Next[i]=P;
    }
  for(int i=0;i<N-1;i++)Flag[Next[i]]=true;
  int Ans=Next[N-1];
  while(Ans&&!Flag[Ans])Ans=Next[Ans-1];
  for(int i=0;i<Ans;i++)putchar(S[i]);
  if(!Ans)printf("Just a legend\n");else putchar('\n');
  return 0;
}