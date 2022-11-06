//program 131D

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

int Parent[3000],Stack[3000];
Graph *G[3000];
bool Cycle[3000],Visited[3000];

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

void Add(int X,int Y)
{
  Graph *P;P=new Graph;
  P->Data=Y;P->Next=G[X];G[X]=P;
}

bool DFS(int V,int Target,int Depth)
{
  Visited[Stack[Depth]=V]=true;
  if(V==Target)
    {
      for(int i=0;i<=Depth;i++)Cycle[Stack[i]]=true;
      return true;
    }
  Graph *P;P=G[V];
  while(P!=NULL)
    {
      if(!Visited[P->Data])if(DFS(P->Data,Target,Depth+1))return true;
      P=P->Next;
    }
  return false;
}

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)Parent[i]=i;
  for(int i=0;i<N;i++)G[i]=NULL;
  memset(Cycle,0,sizeof(Cycle));
  memset(Visited,0,sizeof(Visited));
  for(int i=0;i<N;i++)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      if(Root(X)==Root(Y))DFS(X,Y,0);
      Parent[Root(X)]=Root(Y);
      Add(X,Y);Add(Y,X);
    }
  int F=0,R=0,Queue[3000],Dist[3000];
  memset(Dist,0,sizeof(Dist));
  for(int i=0;i<N;i++)if(Cycle[i])Queue[R++]=i;
  while(R<N)
    {
      int V=Queue[F++];
      Graph *P;P=G[V];
      while(P!=NULL)
        {
          if(!Cycle[P->Data])
            {
              Queue[R++]=P->Data;
              Cycle[P->Data]=true;
              Dist[P->Data]=Dist[V]+1;
            }
          P=P->Next;
        }
    }
  for(int i=0;i<N;i++)cout<<Dist[i]<<((i==N-1)?'\n':' ');
  return 0;
}