//program 125E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct EdgeType
{
  int V1,V2,Number;
  double W;
};

int N,M;
int Parent[5000];
int V1[100000],V2[100000],W[100000];
bool Flag[100000];
EdgeType Edge[1000000];

bool Cmp(EdgeType A,EdgeType B)
{
  return A.W<B.W;
}

int Root(int X)
{
  return (Parent[X]==X)?X:(Parent[X]=Root(Parent[X]));
}

int Calc(double T)
{
  for(int i=0;i<M;i++)
    {
      Edge[i].V1=V1[i]-1;
      Edge[i].V2=V2[i]-1;
      Edge[i].W=W[i];
      if(V1[i]==1||V2[i]==1)Edge[i].W+=T;
      Edge[i].Number=i;
    }
  sort(Edge,Edge+M,Cmp);
  for(int i=0;i<N;i++)Parent[i]=i;
  memset(Flag,0,sizeof(Flag));
  int Total=0;
  for(int i=0;i<M;i++)
    if(Root(Edge[i].V1)!=Root(Edge[i].V2))
      {
        Parent[Root(Edge[i].V1)]=Root(Edge[i].V2);
        Flag[Edge[i].Number]=true;
        if(!Edge[i].V1||!Edge[i].V2)Total++;
      }
  return Total;
}

int main()
{
  int K;cin>>N>>M>>K;
  for(int i=0;i<M;i++)scanf("%d%d%d",&V1[i],&V2[i],&W[i]);
  double Left=-1000000,Right=1000000;int Count;
  for(int i=0;i<100;i++)
    {
      double Mid=(Left+Right)/2;Count=Calc(Mid);
      if(Count==K)break;
      if(Count>K)Left=Mid;else Right=Mid;
    }
  if(Count!=K)
    cout<<-1<<endl;
  else
    {
      cout<<N-1<<endl;int Number=0;
      for(int i=0;i<M;i++)
        if(Flag[i])
          {cout<<i+1;putchar((++Number==N-1)?'\n':' ');}
    }
  return 0;
}