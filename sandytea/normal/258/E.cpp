//program 258-E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Event
{
  int X,L,R,Flag;
};

bool operator <(Event A,Event B)
{
  return A.X<B.X;
}

int Counter;
vector<int> G[100000];
int Path[100000],Begin[100000],End[100000];
int Left[262144],Right[262144],Delta[262144],Sum[262144];

void DFS(int X,int Last)
{
  Path[Counter]=X;
  Begin[X]=Counter++;
  for(int i=0;i<G[X].size();i++)
    if(G[X][i]!=Last)
      DFS(G[X][i],X);
  End[X]=Counter-1;
}

void Build(int P,int L,int R)
{
  Left[P]=L;
  Right[P]=R;
  if(L<R)
    {
      int Mid=(L+R)/2;
      Build(P*2,L,Mid);
      Build(P*2+1,Mid+1,R);
    }
}

void Add(int P,int L,int R,int D)
{
  if(Left[P]==L&&Right[P]==R)
    Delta[P]+=D;
  else
    {
      int Mid=(Left[P]+Right[P])/2;
      if(R<=Mid)
        Add(P*2,L,R,D);
      else if(L>Mid)
        Add(P*2+1,L,R,D);
      else
        {
          Add(P*2,L,Mid,D);
          Add(P*2+1,Mid+1,R,D);
        }
    }
  Sum[P]=Delta[P]?(Right[P]-Left[P]+1):0;
  if(!Sum[P]&&Left[P]<Right[P])
    Sum[P]=Sum[P*2]+Sum[P*2+1];
}

int main()
{
  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=1;i<N;i++)
    {
      int X,Y;
      scanf("%d%d",&X,&Y);
      X--;
      Y--;
      G[X].push_back(Y);
      G[Y].push_back(X);
    }
  Counter=0;
  DFS(0,-1);
  int Total=0;
  Event E[800000];
  for(int i=0;i<M;i++)
    {
      int X,Y;
      scanf("%d%d",&X,&Y);
      X--;
      Y--;
      int L0=Begin[X],R0=End[X];
      int L1=Begin[Y],R1=End[Y];
      E[Total++]=(Event){L0,L0,R0,1};
      E[Total++]=(Event){R0+1,L0,R0,-1};
      E[Total++]=(Event){L0,L1,R1,1};
      E[Total++]=(Event){R0+1,L1,R1,-1};
      E[Total++]=(Event){L1,L0,R0,1};
      E[Total++]=(Event){R1+1,L0,R0,-1};
      E[Total++]=(Event){L1,L1,R1,1};
      E[Total++]=(Event){R1+1,L1,R1,-1};
    }
  sort(E,E+Total);
  Build(1,0,N-1);
  memset(Delta,0,sizeof(Delta));
  memset(Sum,0,sizeof(Sum));
  static int Ans[100000];
  for(int i=0,j=0;i<N;i++)
    {
      while(j<Total&&E[j].X==i)
        {
          Add(1,E[j].L,E[j].R,E[j].Flag);
          j++;
        }
      Ans[Path[i]]=Sum[1]?(Sum[1]-1):0;
    }
  for(int i=0;i<N;i++)
    {
      printf("%d",Ans[i]);
      putchar((i+1==N)?'\n':' ');
    }
  return 0;
}