//program 120H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Graph
{
  int Data;
  Graph *Next;
};

Graph *G[200];
int Pair[475254],Ans[200];
bool Flag[200];

void Add(int X,int Y)
{
  Graph *P;P=new Graph;
  P->Data=Y;P->Next=G[X];G[X]=P;
}

int Find(int V)
{
  Flag[V]=true;
  Graph *P;P=G[V];
  while(P!=NULL)
    {
      int U=Pair[P->Data];
      if(U==-1||(!Flag[U]&&Find(U)))
        {
          Pair[P->Data]=V;
          Ans[V]=P->Data;
          return 1;
        }
      P=P->Next;
    }
  return 0;
}

void Output(int X)
{
  if(X<26){putchar(X+97);return;}X-=26;
  if(X<676){putchar(X/26+97);putchar(X%26+97);return;}X-=676;
  if(X<17576){putchar(X/676+97);putchar(X/26%26+97);putchar(X%26+97);return;}X-=17576;
  putchar(X/17576+97);putchar(X/676%26+97);putchar(X/26%26+97);putchar(X%26+97);
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int N;cin>>N;
  for(int i=0;i<N;i++)
    {
      string S;cin>>S;int M=S.size();G[i]=NULL;
      for(int A=0;A<M;A++)Add(i,S[A]-97);
      for(int A=0;A+1<M;A++)
        for(int B=A+1;B<M;B++)
          Add(i,(S[A]-97)*26+(S[B]-97)+26);
      for(int A=0;A+2<M;A++)
        for(int B=A+1;B+1<M;B++)
          for(int C=B+1;C<M;C++)
            Add(i,(S[A]-97)*676+(S[B]-97)*26+(S[C]-97)+702);
      for(int A=0;A+3<M;A++)
        for(int B=A+1;B+2<M;B++)
          for(int C=B+1;C+1<M;C++)
            for(int D=C+1;D<M;D++)
              Add(i,(S[A]-97)*17576+(S[B]-97)*676+(S[C]-97)*26+(S[D]-97)+18278);
    }
  for(int i=0;i<475254;i++)Pair[i]=-1;
  int Match=0;
  for(int i=0;i<N;i++){memset(Flag,0,sizeof(Flag));Match+=Find(i);}
  if(Match<N)
    cout<<-1<<endl;
  else
    for(int i=0;i<N;i++){Output(Ans[i]);putchar('\n');}
  return 0;
}