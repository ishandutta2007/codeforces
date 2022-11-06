//program 131E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Queen
{
  int X,Y;
};

int A[100000],B[100000],C[200000],D[200000],Ans[100000];
Queen Q[100000];

bool Cmp(Queen A,Queen B)
{
  if(A.X<B.X)return true;
  if(A.X>B.X)return false;
  return A.Y<B.Y;
}

int main()
{
  int M,N;cin>>M>>N;
  for(int i=0;i<N;i++){scanf("%d%d",&Q[i].X,&Q[i].Y);Q[i].X--;Q[i].Y--;}
  for(int i=0;i<M;i++)A[i]=-1;
  for(int i=0;i<M;i++)B[i]=-1;
  for(int i=0;i<M*2;i++)C[i]=-1;
  for(int i=0;i<M*2;i++)D[i]=-1;
  sort(Q,Q+N,Cmp);
  memset(Ans,0,sizeof(Ans));
  for(int i=0;i<N;i++)
    {
      int x=Q[i].X,y=Q[i].Y;
      if(A[x]!=-1){Ans[A[x]]++;Ans[i]++;}A[x]=i;
      if(B[y]!=-1){Ans[B[y]]++;Ans[i]++;}B[y]=i;
      if(C[x+y]!=-1){Ans[C[x+y]]++;Ans[i]++;}C[x+y]=i;
      if(D[x-y+M]!=-1){Ans[D[x-y+M]]++;Ans[i]++;}D[x-y+M]=i;
    }
  int Count[9];memset(Count,0,sizeof(Count));
  for(int i=0;i<N;i++)Count[Ans[i]]++;
  printf("%d %d %d %d %d %d %d %d %d\n",Count[0],Count[1],Count[2],Count[3],Count[4],Count[5],Count[6],Count[7],Count[8]);
  return 0;
}