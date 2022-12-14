//program 212-A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Edge
{
  int Data,Weight,Cost,Next;
};

const int inf=1000000000;

int G[402];
Edge E[20000];

void Add(int Number,int X,int Y,int W,int C)
{
  E[Number*2]=(Edge){Y,W,C,G[X]};G[X]=Number*2;
  E[Number*2+1]=(Edge){X,0,-C,G[Y]};G[Y]=Number*2+1;
}

bool SPFA(int S,int T,int N)
{
  static int Dist[402],Pre[402],Queue[402];
  static bool Flag[402];
  for(int i=0;i<N;i++)Dist[i]=inf;Dist[S]=0;
  memset(Flag,0,sizeof(Flag));
  int F=0,R=1;Queue[0]=S;
  while(F!=R)
    {
      int V=Queue[F++],P=G[V];
      Flag[V]=false;if(F==N)F=0;
      while(P!=-1)
        {
          int U=E[P].Data;
          if(Dist[V]+E[P].Cost<Dist[U]&&E[P].Weight)
            {
              Dist[U]=Dist[V]+E[P].Cost;Pre[U]=P;
              if(!Flag[U])Flag[Queue[R++]=U]=true;
              if(R==N)R=0;
            }
          P=E[P].Next;
        }
    }
  if(Dist[T]==inf)return false;
  int V=T;
  while(V!=S)
    {
      E[Pre[V]].Weight--;
      E[Pre[V]^1].Weight++;
      V=E[Pre[V]^1].Data;
    }
  return true;
}

int main()
{
  int M,N,K,Total;
  scanf("%d%d%d%d",&M,&N,&K,&Total);
  static int X[5000],Y[5000],Dx[200],Dy[200];
  for(int i=0;i<K;i++)
    {
      scanf("%d%d",&X[i],&Y[i]);
      Dx[--X[i]]++;Dy[--Y[i]]++;
    }
  int Ans=0;
  for(int i=0;i<M;i++)
    if(Dx[i]%Total)Ans++;
  for(int i=0;i<N;i++)
    if(Dy[i]%Total)Ans++;
  printf("%d\n",Ans);
  static int Number[5000];
  memset(Number,0,sizeof(Number));
  for(int Current=Total;Current;Current--)
    {
      int S=M+N,T=M+N+1,Count=K;
      for(int i=0;i<M+N+2;i++)G[i]=-1;
      for(int i=0;i<K;i++)
        if(!Number[i])
          Add(i,X[i],M+Y[i],1,0);
          for(int i=0;i<N;i++)
        {
          Add(Count++,M+i,T,Dy[i]/Current,0);
          if(Dy[i]%Current)Add(Count++,M+i,T,1,1);
        }
      for(int i=0;i<M;i++)
        {
          Add(Count++,S,i,Dx[i]/Current,0);
          if(Dx[i]%Current)Add(Count++,S,i,1,1);
        }
      
      while(SPFA(S,T,M+N+2));
      for(int i=0;i<K;i++)
        if(!Number[i]&&!E[i*2].Weight)
          {
            Number[i]=Current;
            Dx[X[i]]--;Dy[Y[i]]--;
          }
    }
  for(int i=0;i<K;i++)
    {
      printf("%d",Number[i]);
      putchar((i==K-1)?'\n':' ');
    }
  return 0;
}