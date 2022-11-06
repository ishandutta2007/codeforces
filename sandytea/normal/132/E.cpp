//program 132E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXV=600,MAXE=70000,inf=1000000000;

int N,Count;
int G[MAXV],Queue[MAXV],Dist[MAXV],Pre[MAXV],Last[MAXV];
int Data[MAXE],Weight[MAXE],Cost[MAXE],Next[MAXE];
bool Flag[MAXV];

int Calc(int X)
{
  if(!X)return 0;
  return Calc(X/2)+X%2;
}

void Add(int Number,int V1,int V2,int W,int C)
{
  Data[Number]=V2;
  Weight[Number]=W;
  Cost[Number]=C;
  Next[Number]=G[V1];
  G[V1]=Number;
}

void Connect(int V1,int V2,int W,int C)
{
  Add(Count++,V1,V2,W,C);
  Add(Count++,V2,V1,0,-C);
}

int SPFA(int S,int T)
{
  for(int i=0;i<=T;i++)Dist[i]=inf;
  Dist[S]=0;
  memset(Flag,0,sizeof(Flag));
  Queue[0]=S;
  int F=0,R=1;
  while(F!=R)
    {
      int V=Queue[F++];if(F==MAXV)F=0;
      int P=G[V];Flag[V]=false;
      while(P!=-1)
        {
          int U=Data[P];
          if(Weight[P]&&Dist[V]+Cost[P]<Dist[U])
            {
              Dist[U]=Dist[V]+Cost[P];Pre[U]=P;
              if(!Flag[U])Flag[Queue[R++]=U]=true;
              if(R==MAXV)R=0;
            }
          P=Next[P];
        }
    }
  if(Dist[T]==inf)return -1;
  int V=T;
  while(V!=S)
    {
      Weight[Pre[V]]--;
      Weight[Pre[V]^1]++;
      int U=Data[Pre[V]^1];
      if(U<=N&&V>N)Last[V-N-1]=U;
      V=U;
    }
  return Dist[T];
}

int main()
{
  int M;cin>>N>>M;
  int A[250];for(int i=0;i<N;i++)cin>>A[i];
  int S=N*2+1,T=N*2+2;Count=0;
  for(int i=0;i<=T;i++)G[i]=-1;
  for(int i=0;i<N;i++)Connect(S,i,1,0);
  Connect(S,N,M,0);
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
      if(A[i]==A[j])
        Connect(i,N+j+1,1,0);
      else
        Connect(i,N+j+1,1,Calc(A[j]));
  for(int i=0;i<N;i++)Connect(N,N+i+1,1,Calc(A[i]));
  for(int i=1;i<=N;i++)Connect(N+i,T,1,0);
  int Ans=0,Tmp;
  while(Tmp=SPFA(S,T),Tmp!=-1)Ans+=Tmp;
  int Total=N;
  for(int i=0;i<N;i++)
    if(Last[i]==N||A[Last[i]]!=A[i])
      Total++;
  cout<<Total<<' '<<Ans<<endl;
  int Number=0,Var[250];
  for(int i=0;i<N;i++)
    if(Last[i]==N)
      {
        Var[i]=Number++;
        printf("%c=%d\nprint(%c)\n",Var[i]+97,A[i],Var[i]+97);
      }
    else if(A[i]==A[Last[i]])
      {
        Var[i]=Var[Last[i]];
        printf("print(%c)\n",Var[i]+97);
      }
    else
      {
        Var[i]=Var[Last[i]];
        printf("%c=%d\nprint(%c)\n",Var[i]+97,A[i],Var[i]+97);
      }
  return 0;
}