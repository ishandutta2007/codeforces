//program 140B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int Like[300],Rank[300][300];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      {int x;scanf("%d",&x);Rank[i][x-1]=j;}
  for(int i=0;i<N;i++)
    {int x;scanf("%d",&x);Like[x-1]=i;}
  int Best[300],Ans[300];
  for(int i=0;i<N;i++)Best[i]=-1;
  int P=-1,Q=-1;
  for(int i=0;i<N;i++)
    {
      if(Q==-1||Like[i]<Like[Q])Q=i;
      if(P==-1||Like[Q]<Like[P]){int Tmp=P;P=Q;Q=Tmp;}
      for(int j=0;j<N;j++)
        {
          int T=(P==j)?Q:P;
          if(T!=-1&&(Best[j]==-1||Rank[j][T]<Rank[j][Best[j]])){Best[j]=T;Ans[j]=i+1;}
        }
    }
  for(int i=0;i<N;i++)
    if(i==N-1)
      printf("%d\n",Ans[i]);
    else
      printf("%d ",Ans[i]);
  return 0;
}