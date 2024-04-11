//program 95A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int M;cin>>M;
  string S[100];for(int i=0;i<M;i++)cin>>S[i];
  string T;cin>>T;
  char Letter;while(Letter=getchar(),Letter<'a'||Letter>'z');
  int N=T.size();bool Flag[100];
  for(int i=0;i<N;i++)if(Flag[i]=(T[i]<'a'))T[i]+=32;
  for(int i=0;i<M;i++)
    for(int j=0;j<S[i].size();j++)
      if(S[i][j]<'a')S[i][j]+=32;
  bool Covered[100];memset(Covered,0,sizeof(Covered));
  for(int i=0;i<M;i++)
    for(int j=0;j+S[i].size()<=N;j++)
      {
        bool Flag=true;
        for(int k=0;Flag&&k<S[i].size();k++)Flag=(S[i][k]==T[j+k]);
        if(Flag)for(int k=0;k<S[i].size();k++)Covered[j+k]=true;
      }
  for(int i=0;i<N;i++)
    {
      char c=T[i];
      if(Covered[i])
        if(c!=Letter)c=Letter;
        else if(c!='a')c='a';
        else c='b';
      putchar(Flag[i]?(c-32):c);
    }
  putchar('\n');
  return 0;
}