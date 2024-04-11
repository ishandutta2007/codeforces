//program 152E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int R,C;
int V[100][100],P[7],Q[7],Path[200][200],Log[65],F[128][200];
char Map[200];

void PaintPath(int A,int B)
{
  Map[A]=Map[B]='X';
  if(Path[A][B]!=-1){PaintPath(A,Path[A][B]);PaintPath(Path[A][B],B);}
}

void Paint(int Mask,int W)
{
  Map[W]='X';
  if(!(Mask&(Mask-1))){PaintPath(W,P[Log[Mask]]*C+Q[Log[Mask]]);return;}
  for(int i=1;i<Mask;i++)
    if((Mask&i)==i&&F[i][W]+F[Mask^i][W]==F[Mask][W])
      {Paint(i,W);Paint(Mask^i,W);return;}
  int X=W/C,Y=W%C;
  if(X&&F[Mask][W]==F[Mask][W-C]+V[X-1][Y]){Paint(Mask,W-C);return;}
  if(X+1<R&&F[Mask][W]==F[Mask][W+C]+V[X+1][Y]){Paint(Mask,W+C);return;}
  if(Y&&F[Mask][W]==F[Mask][W-1]+V[X][Y-1]){Paint(Mask,W-1);return;}
  if(Y+1<C&&F[Mask][W]==F[Mask][W+1]+V[X][Y+1]){Paint(Mask,W+1);return;}
}

int main()
{
  int K;cin>>R>>C>>K;
  for(int i=0;i<R;i++)for(int j=0;j<C;j++)cin>>V[i][j];
  for(int i=0;i<K;i++){cin>>P[i]>>Q[i];P[i]--;Q[i]--;}
  int N=R*C,G[200][200];
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)G[i][j]=(i==j)?0:inf;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)Path[i][j]=-1;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      {
        int T=i*C+j;
        if(i)G[T][T-C]=V[i-1][j];
        if(i+1<R)G[T][T+C]=V[i+1][j];
        if(j)G[T][T-1]=V[i][j-1];
        if(j+1<C)G[T][T+1]=V[i][j+1];
      }
  for(int k=0;k<N;k++)
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(G[i][k]+G[k][j]<G[i][j])
          {
            G[i][j]=G[i][k]+G[k][j];
            Path[i][j]=k;
          }
  for(int i=0;i<7;i++)Log[1<<i]=i;
  for(int i=1;i<(1<<K);i++)
    if(!(i&(i-1)))
      {
        int T=P[Log[i]]*C+Q[Log[i]];
        for(int j=0;j<N;j++)F[i][j]=G[j][T];
      }
    else
      {
        for(int j=0;j<N;j++)F[i][j]=inf;
        for(int j=0;j<N;j++)
          for(int k=1;k<i;k++)
            if((i&k)==k)
              F[i][j]=min(F[i][j],F[k][j]+F[i^k][j]);
        while(true)
          {
            bool Flag=false;
            for(int j=0;j<R;j++)
              for(int k=0;k<C;k++)
                {
                  int T=j*C+k;
                  if(j&&F[i][T-C]+V[j-1][k]<F[i][T]){F[i][T]=F[i][T-C]+V[j-1][k];Flag=true;}
                  if(j+1<R&&F[i][T+C]+V[j+1][k]<F[i][T]){F[i][T]=F[i][T+C]+V[j+1][k];Flag=true;}
                  if(k&&F[i][T-1]+V[j][k-1]<F[i][T]){F[i][T]=F[i][T-1]+V[j][k-1];Flag=true;}
                  if(k+1<C&&F[i][T+1]+V[j][k+1]<F[i][T]){F[i][T]=F[i][T+1]+V[j][k+1];Flag=true;}
                }
            if(!Flag)break;
          }
      }
  int Ans=inf,Best=0;
  for(int i=0;i<N;i++)if(F[(1<<K)-1][i]+V[i/C][i%C]<Ans)Ans=F[(1<<K)-1][Best=i]+V[i/C][i%C];
  cout<<Ans<<endl;
  for(int i=0;i<N;i++)Map[i]='.';
  Paint((1<<K)-1,Best);
  for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)putchar(Map[i*C+j]);
      putchar('\n');
    }
  return 0;
}