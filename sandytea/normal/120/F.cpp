//program 120F

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

Tree *G[100];
bool Flag[100];
int D1[100],D2[100];

void Add(int X,int Y)
{
  Tree *P;P=new Tree;
  P->Data=Y;P->Next=G[X];G[X]=P;
}

int DFS(int X)
{
  D1[X]=D2[X]=0;Flag[X]=true;
  Tree *P;P=G[X];int Max=0;
  while(P!=NULL)
    {
      int Y=P->Data;P=P->Next;
      if(!Flag[Y])
        {
          Max=max(DFS(Y),Max);D2[X]=max(D2[X],D1[Y]+1);
          if(D1[X]<D2[X]){D1[X]+=D2[X];D2[X]=D1[X]-D2[X];D1[X]-=D2[X];}
        }
    }
  return max(D1[X]+D2[X],Max);
}

int GetTree()
{
  int N;cin>>N;for(int i=0;i<N;i++)G[i]=NULL;
  for(int i=1;i<N;i++){int X,Y;cin>>X>>Y;X--;Y--;Add(X,Y);Add(Y,X);}
  memset(Flag,0,sizeof(Flag));
  return DFS(0);
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int M;cin>>M;
  int Ans=0;while(M--)Ans+=GetTree();
  cout<<Ans<<endl;
  return 0;
}