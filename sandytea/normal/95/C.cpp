//program 95C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
  int Data;
  long long Weight;
};

bool operator <(Node A,Node B)
{
  return A.Weight>B.Weight;
}

const long long inf=1000000000000000000LL;

vector<Node> G[1000];
long long Dist[1000][1000];

void Dijkstra(int N,int S)
{
  priority_queue<Node> Heap;
  Heap.push((Node){S,0});
  for(int i=0;i<N;i++)Dist[S][i]=(i==S)?0:inf;
  bool Flag[1000];memset(Flag,0,sizeof(Flag));
  while(!Heap.empty())
    {
      Node V=Heap.top();Heap.pop();
      if(Flag[V.Data])continue;Flag[V.Data]=true;
      for(int i=0;i<G[V.Data].size();i++)
        {
          int X=G[V.Data][i].Data;long long W=G[V.Data][i].Weight;
          if(Dist[S][V.Data]+W<Dist[S][X])
            {
              Dist[S][X]=Dist[S][V.Data]+W;
              Heap.push((Node){X,Dist[S][X]});
            }
        }
    }
}

int main()
{
  int N,M,S,T;cin>>N>>M>>S>>T;S--;T--;
  while(M--)
    {
      int X,Y;long long W;
      cin>>X>>Y>>W;X--;Y--;
      G[X].push_back((Node){Y,W});
      G[Y].push_back((Node){X,W});
    }
  for(int i=0;i<N;i++)Dijkstra(N,i);
  for(int i=0;i<N;i++)G[i].clear();
  for(int i=0;i<N;i++)
    {
      long long Max,Cost;cin>>Max>>Cost;
      for(int j=0;j<N;j++)
        if(Dist[i][j]<=Max)
          G[i].push_back((Node){j,Cost});
    }
  Dijkstra(N,S);
  cout<<((Dist[S][T]==inf)?-1:Dist[S][T])<<endl;
  return 0;
}