//program 141D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Graph
{
  int V,W,Num;
  Graph *Next;
};

const int inf=1000000000;

int Data[200002],Dist[200002],Queue[200002],Last[200002],Pre[200002];
int V1[100000],V2[100000],Weight[100000],Number[100000],Stack[100000];
bool Flag[200002];
Graph *G[200002];

int Find(int X,int N)
{
  int Left=0,Right=N-1;
  while(true)
    {
      int Mid=(Left+Right)/2;
      if(Data[Mid]==X)return Mid;
      if(Data[Mid]<X)Left=Mid+1;else Right=Mid-1;
    }
}

void Add(int V1,int V2,int Weight,int Number)
{
  Graph *p;p=new Graph;
  p->V=V2;p->W=Weight;p->Num=Number;
  p->Next=G[V1];G[V1]=p;
}

int SPFA(int T)
{
  for(int i=1;i<=T;i++)Dist[i]=inf;
  Dist[0]=Queue[0]=0;memset(Flag,0,sizeof(Flag));
  int F=0,R=1;
  while(F!=R)
    {
      int V=Queue[F++];if(F>T)F=0;Flag[V]=false;
      Graph *p;p=G[V];
      while(p!=NULL)
        {
          int U=p->V;
          if(Dist[V]+p->W<Dist[U])
            {
              Dist[U]=Dist[V]+p->W;
              Last[U]=p->Num;
              Pre[U]=V;
              if(!Flag[U])Flag[Queue[R++]=U]=true;
              if(R>T)R=0;
            }
          p=p->Next;
        }
    }
  return Dist[T];
}

int main()
{
  int Edge,M=0,N=2;
  scanf("%d%d",&Edge,&Data[0]);Data[1]=0;
  for(int i=0;i<Edge;i++)
    {
      int x,d,t,p;scanf("%d%d%d%d",&x,&d,&t,&p);
      int A=x-p,B=x+d,C=t+p;
      if(A>=0&&A+C<B)
        {
          V1[M]=Data[N++]=A;
          V2[M]=Data[N++]=B;
          Weight[M]=C;Number[M++]=i+1;
        }
    }
  sort(Data,Data+N);
  Flag[0]=false;for(int i=1;i<N;i++)Flag[i]=(Data[i]==Data[i-1]);
  int Tmp=N;N=0;for(int i=0;i<Tmp;i++)if(!Flag[i])Data[N++]=Data[i];
  for(int i=0;i<N;i++)G[i]=NULL;
  for(int i=1;i<N;i++){Add(i-1,i,Data[i]-Data[i-1],0);Add(i,i-1,Data[i]-Data[i-1],0);}
  for(int i=0;i<M;i++)Add(Find(V1[i],N),Find(V2[i],N),Weight[i],Number[i]);
  cout<<SPFA(N-1)<<endl;
  int Top=0,V=N-1;
  while(V){if(Last[V])Stack[Top++]=Last[V];V=Pre[V];}
  cout<<Top<<endl;while(Top--)cout<<Stack[Top]<<endl;
  return 0;
}