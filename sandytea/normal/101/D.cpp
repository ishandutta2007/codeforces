//program 101D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge
{
  int Data;
  long long Weight;
};

vector<Edge> G[100000];
long long Ans[100000],Size[100000],Len[100000],Sum[100000];
pair<long long,long long> Data[100000];

bool Cmp(pair<long long,long long> A,pair<long long,long long> B)
{
  return double(A.second)/A.first<double(B.second)/B.first;
}

long long GetAns(int X,int Parent,long long Last)
{
  int M=0;
  Ans[X]=0;Size[X]=1;Len[X]=Last*2;
  for(int i=0;i<G[X].size();i++)
    {
      long long Y=G[X][i].Data,W=G[X][i].Weight;
      if(Y!=Parent)
        {
          GetAns(Y,X,W);
          Ans[X]+=Ans[Y]+W*Size[Y];
          Size[X]+=Size[Y];Len[X]+=Len[Y];
        }
    }
  for(int i=0;i<G[X].size();i++)
    if(G[X][i].Data!=Parent)
      Data[M++]=make_pair(Size[G[X][i].Data],Len[G[X][i].Data]);
  if(M)
    {
      sort(Data,Data+M,Cmp);
      Sum[M-1]=Data[M-1].first;
      for(int i=M-2;i>=0;i--)
        {
          Sum[i]=Data[i].first+Sum[i+1];
          Ans[X]+=Data[i].second*Sum[i+1];
        }
    }
  return Ans[X];
}

int main()
{
  int N;cin>>N;
  for(int i=1;i<N;i++)
    {
      int X,Y,W;cin>>X>>Y>>W;X--;Y--;
      G[X].push_back((Edge){Y,W});
      G[Y].push_back((Edge){X,W});
    }
  printf("%0.10lf\n",double(GetAns(0,0,0))/(N-1));
  return 0;
}