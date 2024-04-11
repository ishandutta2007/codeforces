//program 147A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  char c,S[10000];string Word[5000];
  int Len=0,N=0;
  while(c=getchar(),(c>='a'&&c<='z')||(c==' ')||(c=='.')||(c==',')||(c=='!')||(c=='?'))S[Len++]=c;
  for(int i=0;i<Len;i++)
    if(S[i]>='a'&&S[i]<='z')
      {
        Word[N]=S[i];
        while(i+1<Len&&S[i+1]>='a'&&S[i+1]<='z')
          Word[N]+=S[++i];
        N++;
      }
    else if(S[i]!=' ')
      Word[N++]=S[i];
  for(int i=0;i<N;i++)
    {
      cout<<Word[i];
      if(i+1<N&&Word[i+1][0]>='a'&&Word[i+1][0]<='z')putchar(' ');
    }
  putchar('\n');
  return 0;
}