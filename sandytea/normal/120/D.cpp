//program 120D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int A,B,C;

bool Check(int X,int Y,int Z)
{
  if(X==A&&Y==B&&Z==C)return true;
  if(X==A&&Y==C&&Z==B)return true;
  if(X==B&&Y==A&&Z==C)return true;
  if(X==B&&Y==C&&Z==A)return true;
  if(X==C&&Y==A&&Z==B)return true;
  if(X==C&&Y==B&&Z==A)return true;
  return false;
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int M,N;cin>>M>>N;
  int Map[50][50];for(int i=0;i<M;i++)for(int j=0;j<N;j++)cin>>Map[i][j];
  int Ans=0,Sum[50];cin>>A>>B>>C;
  for(int i=0;i<M;i++){Sum[i]=i?Sum[i-1]:0;for(int j=0;j<N;j++)Sum[i]+=Map[i][j];}
  for(int i=0;i+2<M;i++)for(int j=i+1;j+1<M;j++)if(Check(Sum[i],Sum[j]-Sum[i],Sum[M-1]-Sum[j]))Ans++;
  for(int i=0;i<N;i++){Sum[i]=i?Sum[i-1]:0;for(int j=0;j<M;j++)Sum[i]+=Map[j][i];}
  for(int i=0;i+2<N;i++)for(int j=i+1;j+1<N;j++)if(Check(Sum[i],Sum[j]-Sum[i],Sum[N-1]-Sum[j]))Ans++;
  cout<<Ans<<endl;
  return 0;
}