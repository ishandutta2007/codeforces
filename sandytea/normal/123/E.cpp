//program 123E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Tree
{
  int Data;
  Tree *Next;
};

Tree *G[100000];
double S[100000],T[100000],Sum1[100000],Sum2[100000];
int Queue[100000],Parent[100000],Size[100000];

void Add(int X,int Y)
{
  Tree *P;P=new Tree;
  P->Data=Y;P->Next=G[X];G[X]=P;
}

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int x=c-48;while(c=getchar(),c>='0'&&c<='9')x=x*10+c-48;
  return x;
}

int main()
{
  int N=GetNumber();
  for(int i=0;i<N;i++)G[i]=NULL;
  for(int i=1;i<N;i++){int X=GetNumber()-1,Y=GetNumber()-1;Add(X,Y);Add(Y,X);}
  double Sum_S=0,Sum_T=0;
  for(int i=0;i<N;i++)
    {
      S[i]=GetNumber();Sum_S+=S[i];
      T[i]=GetNumber();Sum_T+=T[i];
    }
  for(int i=0;i<N;i++)S[i]/=Sum_S;
  for(int i=0;i<N;i++)T[i]/=Sum_T;
  int F=0,R=1;Queue[0]=0;Parent[0]=-1;
  while(R<N)
    {
      int V=Queue[F++];Tree *P;P=G[V];
      while(P!=NULL)
        {
          int U=P->Data;P=P->Next;
          if(U!=Parent[V])Parent[Queue[R++]=U]=V;
        }
    }
  for(int i=N-1;i>=0;i--)
    {
      int V=Queue[i];Size[V]=1;Tree *P;P=G[V];
      while(P!=NULL)
        {
          int U=P->Data;P=P->Next;
          if(U!=Parent[V])Size[V]+=Size[U];
        }
    }
  Sum1[0]=Sum2[0]=0;
  for(int i=1;i<N;i++)
    {
      int V=Queue[i],U=Parent[V];
      Sum1[V]=(N-Size[V])*T[V]+Sum1[U];
      Sum2[V]=Size[V]*T[U]+Sum2[U];
    }
  double Sum=0;for(int i=0;i<N;i++)Sum+=(N-Size[i])*T[i];
  double Ans=0;for(int i=0;i<N;i++)Ans+=S[i]*(Sum-Sum1[i]+Sum2[i]);
  printf("%0.10lf\n",Ans);
  return 0;
}