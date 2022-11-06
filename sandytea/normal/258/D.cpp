//program 258-D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,M;
  scanf("%d%d",&N,&M);
  static int A[1000];
  for(int i=0;i<N;i++)
    scanf("%d",&A[i]);
  static int X[1000],Y[1000];
  for(int i=0;i<M;i++)
    {
      scanf("%d%d",&X[i],&Y[i]);
      X[i]--;
      Y[i]--;
      if(X[i]>Y[i])
        swap(X[i],Y[i]);
    }
  static double P[1000][1000];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      P[i][j]=(A[i]<A[j])?1:0;
  double Ans=0;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
      if(A[i]>A[j])
        Ans++;
  for(int i=0;i<M;i++)
    {
      for(int j=X[i]+1;j<Y[i];j++)
        Ans+=P[X[i]][j]-0.5;
      for(int j=X[i]+1;j<Y[i];j++)
        Ans+=P[j][Y[i]]-0.5;
      Ans+=P[X[i]][Y[i]]-0.5;
      for(int j=0;j<N;j++)
        {
          if(j==X[i]||j==Y[i])
            continue;
          double T0=(P[X[i]][j]+P[Y[i]][j])/2;
          double T1=(P[j][X[i]]+P[j][Y[i]])/2;
          P[X[i]][j]=P[Y[i]][j]=T0;
          P[j][X[i]]=P[j][Y[i]]=T1;
        }
      P[X[i]][Y[i]]=P[Y[i]][X[i]]=0.5;
    }
  printf("%0.10lf\n",Ans);
  return 0;
}