//program 160D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct EdgeType
{
  int X,Y,Weight,Number;
};

struct Graph
{
  int Data,Number;
  Graph *Next;
};

int Counter;
int Parent[100000],Ans[100000],Index[100000],Low[100000],Father[100000],Last[100000],V1[100000],V2[100000];
bool Flag[100000],Visited[100000];
EdgeType Edge[100000];
Graph *G[100000];

bool operator<(EdgeType A,EdgeType B)
{
  return A.Weight<B.Weight;
}

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

void Add(int X,int Y,int Num)
{
  Graph *P;P=new Graph;
  P->Data=Y;P->Number=Num;
  P->Next=G[X];G[X]=P;
}

void DFS(int X)
{
  Index[X]=Low[X]=Counter++;Visited[X]=true;
  Graph *P;P=G[X];
  while(P!=NULL)
    {
      int Y=P->Data;
      if(!Visited[Y])
        {
          Father[Y]=X;Last[Y]=P->Number;
          DFS(Y);Low[X]=min(Low[X],Low[Y]);
        }
      else
        if(P->Number!=Last[X])
          Low[X]=min(Low[X],Index[Y]);
      P=P->Next;
    }
  if(Low[X]==Index[X]&&Father[X]!=-1)Ans[Last[X]]=2;
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<M;i++)
    {
      Edge[i].X=GetNumber()-1;
      Edge[i].Y=GetNumber()-1;
      Edge[i].Weight=GetNumber();
      Edge[i].Number=i;
    }
  sort(Edge,Edge+M);
  for(int i=0;i<N;i++)Parent[i]=i;
  memset(Ans,0,sizeof(Ans));
  for(int i=0;i<M;)
    {
      int P=i,Q=i+1;while(Q<M&&Edge[Q].Weight==Edge[P].Weight)Q++;i=Q;
      for(int j=P;j<Q;j++)
        {
          V1[j]=Root(Edge[j].X);V2[j]=Root(Edge[j].Y);
          if(Flag[j]=(V1[j]!=V2[j]))Ans[Edge[j].Number]=1;
        }
      for(int j=P;j<Q;j++)
        if(Flag[j])
          {
            G[V1[j]]=G[V2[j]]=NULL;
            Visited[V1[j]]=Visited[V2[j]]=false;
            Father[V1[j]]=Father[V2[j]]=-1;
          }
      for(int j=P;j<Q;j++)
        if(Flag[j])
          {Add(V1[j],V2[j],Edge[j].Number);Add(V2[j],V1[j],Edge[j].Number);}
      Counter=0;
      for(int j=P;j<Q;j++)
        if(Flag[j])
          {
            if(!Visited[V1[j]])DFS(V1[j]);
            if(!Visited[V2[j]])DFS(V2[j]);
          }
      for(int j=P;j<Q;j++)Parent[Root(Edge[j].X)]=Root(Edge[j].Y);
    }
  for(int i=0;i<M;i++)
    if(Ans[i]==0)cout<<"none"<<endl;
    else if(Ans[i]==1)cout<<"at least one"<<endl;
    else if(Ans[i]==2)cout<<"any"<<endl;
  return 0;
}