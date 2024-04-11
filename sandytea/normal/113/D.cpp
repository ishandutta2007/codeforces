//program 113D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M,S,T;cin>>N>>M>>S>>T;S--;T--;
  double G[22][22];memset(G,0,sizeof(G));
  int Degree[22];memset(Degree,0,sizeof(Degree));
  while(M--)
    {
      int X,Y;cin>>X>>Y;X--;Y--;
      G[X][Y]=G[Y][X]=1;Degree[X]++;Degree[Y]++;
    }
  for(int i=0;i<N;i++)
    {
      double P,Q;cin>>P;Q=(1-P)/Degree[i];
      for(int j=0;j<N;j++)if(i==j)G[i][j]=P;else G[i][j]*=Q;
    }
  double Result[22];
  int Total=0,Map[22][22];
  for(int i=0;i<N;i++)
    for(int j=0;j<i;j++)
      Map[i][j]=Map[j][i]=Total++;
  for(int Ans=0;Ans<N;Ans++)
    {
      double Matrix[250][250];
      memset(Matrix,0,sizeof(Matrix));
      for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
          {
            Matrix[Map[i][j]][Map[i][j]]=1;
            Matrix[Map[i][j]][Total]=G[i][Ans]*G[j][Ans];
            for(int X=0;X<N;X++)
              for(int Y=0;Y<N;Y++)
                if(X!=Y)Matrix[Map[i][j]][Map[X][Y]]-=G[i][X]*G[j][Y];
          }
      for(int i=0;i<Total-1;i++)
        {
          int p=i;while(Matrix[p][i]==0)p++;
          for(int j=i;j<=Total;j++)swap(Matrix[i][j],Matrix[p][j]);
          for(int j=i+1;j<Total;j++)
            {
              double t=Matrix[j][i]/Matrix[i][i];
              for(int k=i;k<=Total;k++)Matrix[j][k]-=Matrix[i][k]*t;
            }
        }
      double P[250];
      for(int i=Total-1;i>=0;i--)
        {
          for(int j=i+1;j<Total;j++)Matrix[i][Total]-=Matrix[i][j]*P[j];
          P[i]=Matrix[i][Total]/Matrix[i][i];
        }
      printf("%0.10lf",(S==T)?((S==Ans)?1:0):P[Map[S][T]]);
      putchar((Ans==N-1)?'\n':' ');
    }
  return 0;
}