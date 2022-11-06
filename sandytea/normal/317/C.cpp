//program 317-C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Move
{
  int X,Y,W;
};

int Get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool Flag=(c=='-');
  if(Flag)
    c=getchar();
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return Flag?-X:X;
}

void Output(int X)
{
  if(X<0)
    {
      putchar('-');
      X=-X;
    }
  int Len=0,Data[10];
  while(X)
    {
      Data[Len++]=X%10;
      X/=10;
    }
  if(!Len)
    Data[Len++]=0;
  while(Len--)
    putchar(Data[Len]+48);
  putchar('\n');
}

int A[300],B[300];
vector<int> G[300];
int Len;
int Path[300];
bool Flag[300];

bool DFS(int X,int Depth)
{
  if(Flag[X])
    return false;
  Flag[X]=true;
  Path[Depth]=X;
  if(A[X]<B[X])
    {
      Len=Depth+1;
      return true;
    }
  for(int i=0;i<G[X].size();i++)
    if(DFS(G[X][i],Depth+1))
      return true;
  return false;
}

int main()
{
  int N=Get(),MaxV=Get(),M=Get(),Sum=0;
  for(int i=0;i<N;i++)
    A[i]=Get();
  for(int i=0;i<N;i++)
    B[i]=Get();
  for(int i=0;i<M;i++)
    {
      int X=Get()-1,Y=Get()-1;
      G[X].push_back(Y);
      G[Y].push_back(X);
    }
  vector<Move> Ans;
  for(int i=0;i<N;i++)
    while(A[i]>B[i])
      {
        memset(Flag,0,sizeof(Flag));
        if(!DFS(i,0))
          {
            cout<<"NO"<<endl;
            return 0;
          }
        int U=i,V=Path[Len-1];
        int K=min(A[U]-B[U],B[V]-A[V]);
        static int Send[300];
        for(int j=0;j<Len-1;j++)
          {
            int P=Path[j],Q=Path[j+1];
            int Real=min(K,min(A[P],MaxV-A[Q]));
            A[P]-=Real;
            A[Q]+=Real;
            Send[j]=Real;
            if(Real)
              Ans.push_back((Move){P,Q,Real});
          }
        for(int j=Len-1;j;j--)
          {
            int P=Path[j],Q=Path[j-1];
            int Real=min(K-Send[j-1],min(MaxV-A[P],A[Q]));
            A[P]+=Real;
            A[Q]-=Real;
            if(Real)
              Ans.push_back((Move){Q,P,Real});
          }
      }
  for(int i=0;i<N;i++)
    if(A[i]!=B[i])
      {
        cout<<"NO"<<endl;
        return 0;
      }
  cout<<Ans.size()<<endl;
  for(int i=0;i<Ans.size();i++)
    cout<<Ans[i].X+1<<' '<<Ans[i].Y+1<<' '<<Ans[i].W<<endl;
  return 0;
}