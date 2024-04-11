//program 98E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool Visited[1001][1001];
double F[1001][1001];

double DP(int M,int N)
{
  if(Visited[M][N])return F[M][N];
  Visited[M][N]=true;
  if(!N)return F[M][N]=1;
  if(!M)return F[M][N]=1.0/(N+1);
  double A=(double)N/(N+1)*(1-DP(N-1,M)),B=A+1.0/(N+1),C=1,D=1-DP(N,M-1);
  double P=(D-C)/(A-B-C+D);
  return F[M][N]=A*P+C*(1-P);
}

int main()
{
  int M,N;cin>>M>>N;
  memset(Visited,0,sizeof(Visited));
  double Ans=DP(M,N);
  printf("%0.10lf %0.10lf\n",Ans,1-Ans);
  return 0;
}