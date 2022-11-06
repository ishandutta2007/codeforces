//program 159A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int main()
{
  int M,K;cin>>M>>K;
  string A[1000],B[1000];int T[1000];
  for(int i=0;i<M;i++)cin>>A[i]>>B[i]>>T[i];
  string Name[2000];
  set<string> Data;
  map<string,int> Number;
  int N=0,X[1000],Y[1000];
  for(int i=0;i<M;i++)
    {
      if(Data.count(A[i]))
        X[i]=Number[A[i]];
      else
        {
          Data.insert(A[i]);Name[N]=A[i];
          Number[A[i]]=X[i]=N++;
        }
      if(Data.count(B[i]))
        Y[i]=Number[B[i]];
      else
        {
          Data.insert(B[i]);Name[N]=B[i];
          Number[B[i]]=Y[i]=N++;
        }
    }
  bool G[2000][2000];
  for(int i=0;i<M;i++)
    for(int j=i+1;j<M;j++)
      if(T[i]!=T[j]&&T[j]-T[i]<=K&&X[i]==Y[j]&&X[j]==Y[i])
        G[X[i]][Y[i]]=G[X[j]][Y[j]]=true;
  int Total=0;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
      Total+=G[i][j];
  cout<<Total<<endl;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
      if(G[i][j])cout<<Name[i]<<' '<<Name[j]<<endl;
  return 0;
}