//program 150E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge
{
  int Data,Weight;
};

struct SubTree
{
  int V,Depth,Up;
};

bool operator <(SubTree A,SubTree B)
{
  return A.Depth<B.Depth;
}

const int inf=1000000000;

int N,LB,UB,UsedSize=0,M;
int Ans_V1,Ans_V2,Ans,Path_S,Path_T;
vector<Edge> G[100000];
bool Used[100000];
int Queue[100000],Parent[100000],Size[100000],Depth[100000],Sum[100000];
SubTree Memory[1000000];
int Max1[100000],MaxV1[100000],Max2[100000],MaxV2[100000],Deque[100000];

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

int GetGravity(int Root)
{
  int Front=0;M=1;
  Queue[0]=Root;Parent[Root]=-1;
  while(Front<M)
    {
      int V=Queue[Front++];
      for(int i=0;i<G[V].size();i++)
        if(G[V][i].Data!=Parent[V]&&!Used[G[V][i].Data])
          Parent[Queue[M++]=G[V][i].Data]=V;
    }
  int Min=inf,Ans;
  for(int i=M-1;i>=0;i--)
    {
      int V=Queue[i],Max=0;Size[V]=1;
      for(int j=0;j<G[V].size();j++)
        if(G[V][j].Data!=Parent[V]&&!Used[G[V][j].Data])
          {
            Size[V]+=Size[G[V][j].Data];
            Max=max(Max,Size[G[V][j].Data]);
          }
      Max=max(Max,M-Size[V]);
      if(Max<Min){Min=Max;Ans=V;}
    }
  return Ans;
}

int GetDepth(int Root)
{
  int Front=0,M=1;
  Queue[0]=Root;Parent[Root]=-1;Depth[Root]=1;
  while(Front<M)
    {
      int V=Queue[Front++];
      for(int i=0;i<G[V].size();i++)
        {
          int U=G[V][i].Data;
          if(U!=Parent[V]&&!Used[U])
            Depth[Queue[M++]=U]=Depth[Parent[U]=V]+1;
        }
    }
  return Depth[Queue[M-1]];
}

bool Check(int Ans,int Root,int Lower,int Upper)
{
  Max1[0]=0;MaxV1[0]=Root;for(int i=1;i<M;i++)Max1[i]=-inf;int MaxDepth=0;
  for(int i=Lower;i<Upper;i++)
    {
      for(int j=0;j<=Memory[i].Depth;j++)Max2[j]=-inf;
      int Front=0,Tail=1,Start=Memory[i].V;
      Queue[0]=Start;Parent[Start]=-1;Depth[Start]=1;Sum[Start]=Max2[1]=(Memory[i].Up>=Ans)?1:-1;MaxV2[1]=Start;
      while(Front<Tail)
        {
          int V=Queue[Front++];
          for(int j=0;j<G[V].size();j++)
            {
              int U=G[V][j].Data;
              if(!Used[U]&&U!=Parent[V])
                {
                  Parent[Queue[Tail++]=U]=V;
                  Depth[U]=Depth[V]+1;
                  Sum[U]=Sum[V]+((G[V][j].Weight>=Ans)?1:-1);
                  if(Sum[U]>Max2[Depth[U]])
                    {
                      Max2[Depth[U]]=Sum[U];
                      MaxV2[Depth[U]]=U;
                    }
                }
            }
        }
      int F=0,R=0,Top=min(Memory[i].Depth,UB);
      for(int j=0;j<=MaxDepth&&Top;j++)
        {
          while(F<R&&Max1[j]>=Max1[Deque[R-1]])R--;Deque[R++]=j;
          while(Top&&min(UB-Top,MaxDepth)==j)
            {
              while(F<R&&Deque[F]<max(LB-Top,0))F++;
              if(F<R&&Max1[Deque[F]]+Max2[Top]>=0){Path_S=MaxV1[Deque[F]];Path_T=MaxV2[Top];return true;}
              Top--;
            }
        }
      for(int j=1;j<=Memory[i].Depth;j++)
        if(Max2[j]>Max1[j])
          {Max1[j]=Max2[j];MaxV1[j]=MaxV2[j];}
      MaxDepth=max(MaxDepth,Memory[i].Depth);
    }
  return false;
}

void GetPath(int Root)
{
  Root=GetGravity(Root);Used[Root]=true;
  if(M<=LB)return;
  int Lower=UsedSize;
  for(int i=0;i<G[Root].size();i++)
    if(!Used[G[Root][i].Data])
      {
        Memory[UsedSize].V=G[Root][i].Data;
        Memory[UsedSize].Depth=GetDepth(G[Root][i].Data);
        Memory[UsedSize].Up=G[Root][i].Weight;
        UsedSize++;
      }
  int Upper=UsedSize;
  sort(Memory+Lower,Memory+Upper);
  int Left=-1,Right=1000000001;
  while(Left<Right)
    {
      int Mid=(Left+Right+1)/2;
      if(Check(Mid,Root,Lower,Upper))Left=Mid;else Right=Mid-1;
    }
  if(Left>Ans){Ans=Left;Ans_V1=Path_S+1;Ans_V2=Path_T+1;}
  for(int i=0;i<G[Root].size();i++)if(!Used[G[Root][i].Data])GetPath(G[Root][i].Data);
}

int main()
{
  N=GetNumber();LB=GetNumber();UB=GetNumber();
  for(int i=1;i<N;i++)
    {
      int X=GetNumber()-1,Y=GetNumber()-1,W=GetNumber();
      G[X].push_back((Edge){Y,W});G[Y].push_back((Edge){X,W});
    }
  memset(Used,0,sizeof(Used));
  Ans=-inf;GetPath(0);
  cout<<Ans_V1<<' '<<Ans_V2<<endl;
  return 0;
}