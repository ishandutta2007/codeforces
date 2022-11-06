//program 144D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct Graph
{
  int Data,Weight;
  Graph *Next;
};

struct DataType
{
  int X,Y;
  bool operator <(const DataType A)const
    {
      return A.Y<Y;
    }
};

Graph *G[100000];
int Dist[100000];
bool Visited[100000];
priority_queue<DataType> Queue;

void Add(int X,int Y,int Z)
{
  Graph *p;p=new Graph;
  p->Data=Y;p->Weight=Z;p->Next=G[X];G[X]=p;
}

void Dijkstra(int S)
{
  for(int i=0;i<100000;i++)Dist[i]=2000000000;
  Dist[S]=0;memset(Visited,0,sizeof(Visited));
  DataType T;T.X=S;T.Y=0;Queue.push(T);
  while(!Queue.empty())
    {
      int V=Queue.top().X;Queue.pop();
      if(Visited[V])continue;
      Graph *p;p=G[V];Visited[V]=true;
      while(p!=NULL)
        {
          int U=p->Data;
          if(Dist[V]+p->Weight<Dist[U])
            {
              Dist[U]=Dist[V]+p->Weight;
              T.X=U;T.Y=Dist[U];Queue.push(T);
            }
          p=p->Next;
        }
    }
}

int main()
{
  int N,M,S;cin>>N>>M>>S;S--;
  for(int i=0;i<N;i++)G[i]=NULL;
  while(M--)
    {
      int X,Y,Z;scanf("%d%d%d",&X,&Y,&Z);
      X--;Y--;Add(X,Y,Z);Add(Y,X,Z);
    }
  Dijkstra(S);
  int Len,Ans=0;cin>>Len;
  for(int i=0;i<N;i++)
    if(Dist[i]==Len)
      Ans++;
    else if(Dist[i]<Len)
      {
        Graph *p;p=G[i];
        while(p!=NULL)
          {
            int j=p->Data;
            if(Dist[i]+p->Weight>Len)
              if(Dist[i]+Dist[j]+p->Weight>Len*2)
                Ans++;
              else if(Dist[i]+Dist[j]+p->Weight==Len*2&&i<j)
                Ans++;
            p=p->Next;
          }
      }
  printf("%d\n",Ans);
  return 0;
}