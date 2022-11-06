//program 103E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct EdgeType
{
  int Data,Weight,Next;
};

const int inf=1000000000;

int Data[90000];
int H[400];
vector<int> Set[300],G[300];
bool Visited[300];
int Pair[90000];
EdgeType Edge[200000];

int Find(int N,int X)
{
  int Left=0,Right=N-1;
  while(true)
    {
      int Mid=(Left+Right)/2;
      if(Data[Mid]==X)return Mid;
      if(Data[Mid]<X)Left=Mid+1;else Right=Mid-1;
    }
}

bool FindPath(int X)
{
  Visited[X]=true;
  for(int i=0;i<G[X].size();i++)
    {
      int Y=Pair[G[X][i]];
      if(Y==-1||(!Visited[Y]&&FindPath(Y)))
        {Pair[G[X][i]]=X;return true;}
    }
  return false;
}

void Add(int Number,int X,int Y,int W)
{
  Edge[Number].Data=Y;
  Edge[Number].Weight=W;
  Edge[Number].Next=H[X];
  H[X]=Number;
}

void Link(int Number,int X,int Y,int W)
{
  Add(Number*2,X,Y,W);
  Add(Number*2+1,Y,X,0);
}

int MaxFlow(int S,int T)
{
  int Dist[400],Start[400],Count[400],Pre[400];
  memset(Dist,0,sizeof(Dist));
  for(int i=0;i<=T;i++)Start[i]=H[i];
  memset(Count,0,sizeof(Count));Count[0]=T+1;
  int V=S,Flow=inf,Ans=0;
  while(Dist[S]<=T)
    {
      int P=Start[V];
      while(P!=-1)
        {
          if(Dist[V]==Dist[Edge[P].Data]+1&&Edge[P].Weight>0)break;
          P=Edge[P].Next;
        }
      if(P!=-1)
        {
          Start[V]=P;Pre[V=Edge[P].Data]=P;
          Flow=min(Flow,Edge[P].Weight);
          if(V==T)
            {
              Ans+=Flow;
              while(V!=S)
                {
                  Edge[Pre[V]].Weight-=Flow;
                  Edge[Pre[V]^1].Weight+=Flow;
                  V=Edge[Pre[V]^1].Data;
                }
            }
        }
      else
        {
          int Min=T+2,P=H[V];
          while(P!=-1)
            {
              if(Dist[Edge[P].Data]+1<Min&&Edge[P].Weight>0)
                {
                  Min=Dist[Edge[P].Data]+1;
                  Start[V]=P;
                }
              P=Edge[P].Next;
            }
          if(!(--Count[Dist[V]]))break;
          Count[Dist[V]=Min]++;
          if(V!=S)V=Edge[Pre[V]^1].Data;
        }
    }
  return Ans;
}

int main()
{
  int N,M=0;cin>>N;
  for(int i=0;i<N;i++)
    {
      int Total;cin>>Total;
      for(int j=0;j<Total;j++)
        {int X;cin>>X;Set[i].push_back(X);Data[M++]=X;}
    }
  int V[301];for(int i=0;i<N;i++)cin>>V[i];V[N]=inf;
  sort(Data,Data+M);
  int Tmp=M;M=0;
  for(int i=0;i<Tmp;i++)
    if(!i||Data[i]!=Data[i-1])
      Data[M++]=Data[i];
  for(int i=0;i<N;i++)
    for(int j=0;j<Set[i].size();j++)
      G[i].push_back(Set[i][j]=Find(M,Set[i][j]));
  for(int i=0;i<M;i++)Pair[i]=-1;
  for(int i=0;i<N;i++)
    {
      memset(Visited,0,sizeof(Visited));
      FindPath(i);
    }
  for(int i=0;i<M;i++)if(Pair[i]==-1)Pair[i]=N;
  int S=N+1,T=N+2,Count=0;
  for(int i=0;i<=T;i++)H[i]=-1;
  for(int i=0;i<=N;i++)if(V[i]<0)Link(Count++,S,i,-V[i]);else Link(Count++,i,T,V[i]);
  for(int i=0;i<N;i++)
    for(int j=0;j<Set[i].size();j++)
      if(Pair[Set[i][j]]!=i)
        Link(Count++,i,Pair[Set[i][j]],inf);
  int Ans=MaxFlow(S,T);
  for(int i=0;i<N;i++)if(V[i]<0)Ans+=V[i];
  cout<<Ans<<endl;
  return 0;
}