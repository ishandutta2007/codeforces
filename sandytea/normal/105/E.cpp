//program 105E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

struct Player
{
  int X,Y,P,Walk,Throw;
};

bool operator >(Player A,Player B)
{
  return A.Y>B.Y;
}

int Ans=0;
int W0,W1,W2,T0,T1,T2;
set<int> Set;

int V(Player A)
{
  return (A.X-1)*24+A.Y*8+A.P;
}

int Calculate(Player A,Player B,Player C)
{
  Player D,E,F;
  if(A.Walk==W0&&A.Throw==T0&&B.Walk==W1&&B.Throw==T1&&C.Walk==W2&&C.Throw==T2){D=A;E=B;F=C;}
  if(A.Walk==W0&&A.Throw==T0&&C.Walk==W1&&C.Throw==T1&&B.Walk==W2&&B.Throw==T2){D=A;E=C;F=B;}
  if(B.Walk==W0&&B.Throw==T0&&A.Walk==W1&&A.Throw==T1&&C.Walk==W2&&C.Throw==T2){D=B;E=A;F=C;}
  if(B.Walk==W0&&B.Throw==T0&&C.Walk==W1&&C.Throw==T1&&A.Walk==W2&&A.Throw==T2){D=B;E=C;F=A;}
  if(C.Walk==W0&&C.Throw==T0&&A.Walk==W1&&A.Throw==T1&&B.Walk==W2&&B.Throw==T2){D=C;E=A;F=B;}
  if(C.Walk==W0&&C.Throw==T0&&B.Walk==W1&&B.Throw==T1&&A.Walk==W2&&A.Throw==T2){D=C;E=B;F=A;}
  return V(D)*1440000+V(E)*1200+V(F);
}

void DFS(Player A,Player B,Player C)
{
  Ans=max(Ans,A.X);Ans=max(Ans,B.X);Ans=max(Ans,C.X);
  if(!A.P&&!B.P&&!C.P)return;
  if(A>B)swap(A,B);if(A>C)swap(A,C);if(B>C)swap(B,C);
  int Tmp=Calculate(A,B,C);
  if(Set.count(Tmp))return;
  Set.insert(Tmp);
  if(A.Y==0&&B.Y==1&&C.Y==2&&(A.P&4))
    for(int i=max(A.X-A.Throw,1);i<=A.X+A.Throw;i++)
      if(i!=A.X)
        {
          Player D=A,E=B,F=C;
          D.P^=4;E.X=F.X=i;E.Y=0;F.Y=1;
          DFS(D,E,F);
        }
  if(A.Y==0&&B.Y==0&&C.Y==1)
    {
      if(A.X==C.X)swap(A,B);
      if(A.P&1)
        for(int i=max(A.X-A.Walk,1);i<=A.X+A.Walk;i++)
          if(i!=B.X)
            {
              Player D=A,E=B,F=C;
              D.P^=1;D.X=i;
              DFS(D,E,F);
            }
      if((A.P&2)&&abs(A.X-B.X)==1)
        {
          Player D=A,E=B,F=C;
          D.P^=2;E.X=F.X=A.X;E.Y=1;F.Y=2;
          DFS(D,E,F);
        }
      if(B.P&4)
        for(int i=max(B.X-B.Throw,1);i<=B.X+B.Throw;i++)
          if(i!=A.X&&i!=B.X)
            {
              Player D=A,E=B,F=C;
              E.P^=4;F.X=i;F.Y=0;
              DFS(D,E,F);
            }
    }
  if(A.Y==0&&B.Y==0&&C.Y==0)
    {
      if(A.P&1)
        for(int i=max(A.X-A.Walk,1);i<=A.X+A.Walk;i++)
          if(i!=B.X&&i!=C.X)
            {
              Player D=A,E=B,F=C;
              D.P^=1;D.X=i;
              DFS(D,E,F);
            }
      if(B.P&1)
        for(int i=max(B.X-B.Walk,1);i<=B.X+B.Walk;i++)
          if(i!=A.X&&i!=C.X)
            {
              Player D=A,E=B,F=C;
              E.P^=1;E.X=i;
              DFS(D,E,F);
            }
      if(C.P&1)
        for(int i=max(C.X-C.Walk,1);i<=C.X+C.Walk;i++)
          if(i!=A.X&&i!=B.X)
            {
              Player D=A,E=B,F=C;
              F.P^=1;F.X=i;
              DFS(D,E,F);
            }
      if(abs(A.X-B.X)==1)
        {
          if(A.P&2)
            {
              Player D=A,E=B,F=C;
              D.P^=2;E.X=D.X;E.Y=1;
              DFS(D,E,F);
            }
          if(B.P&2)
            {
              Player D=A,E=B,F=C;
              E.P^=2;D.X=E.X;D.Y=1;
              DFS(D,E,F);
            }
        }
      if(abs(A.X-C.X)==1)
        {
          if(A.P&2)
            {
              Player D=A,E=B,F=C;
              D.P^=2;F.X=D.X;F.Y=1;
              DFS(D,E,F);
            }
          if(C.P&2)
            {
              Player D=A,E=B,F=C;
              F.P^=2;D.X=F.X;D.Y=1;
              DFS(D,E,F);
            }
        }
      if(abs(B.X-C.X)==1)
        {
          if(B.P&2)
            {
              Player D=A,E=B,F=C;
              E.P^=2;F.X=E.X;F.Y=1;
              DFS(D,E,F);
            }
          if(C.P&2)
            {
              Player D=A,E=B,F=C;
              F.P^=2;E.X=F.X;E.Y=1;
              DFS(D,E,F);
            }
        }
    }
}

int main()
{
  Player A;cin>>A.X>>A.Walk>>A.Throw;A.Y=0;A.P=7;W0=A.Walk;T0=A.Throw;
  Player B;cin>>B.X>>B.Walk>>B.Throw;B.Y=0;B.P=7;W1=B.Walk;T1=B.Throw;
  Player C;cin>>C.X>>C.Walk>>C.Throw;C.Y=0;C.P=7;W2=C.Walk;T2=C.Throw;
  DFS(A,B,C);
  cout<<Ans<<endl;
  return 0;
}