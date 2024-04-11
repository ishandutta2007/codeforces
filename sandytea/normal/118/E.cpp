//program 118E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

bool Flag=true;
int Count=0;
int Index[100000],Low[100000];
vector<int> G[100000];
pair<int,int> Edge[300000];
map< pair<int,int> , pair<int,int> > Ans;

int GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  int X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void DFS(int V,int Last)
{
  Index[V]=Low[V]=Count++;
  for(int i=0;i<G[V].size();i++)
    {
      int U=G[V][i];if(U==Last)continue;
      pair<int,int> E=make_pair(min(U,V),max(U,V));
      if(Index[U]==-1)
        {
          DFS(U,V);Low[V]=min(Low[V],Low[U]);
          if(Low[U]==Index[U])Flag=false;
          Ans[E]=make_pair(V,U);
        }
      else
        {
          Low[V]=min(Low[V],Index[U]);
          if(Index[U]<Index[V])Ans[E]=make_pair(V,U);
        }
    }
}

int main()
{
  int N=GetNumber(),M=GetNumber();
  for(int i=0;i<M;i++)
    {
      int X=GetNumber()-1,Y=GetNumber()-1;
      G[X].push_back(Y);G[Y].push_back(X);
      Edge[i]=make_pair(min(X,Y),max(X,Y));
    }
  for(int i=0;i<N;i++)Index[i]=-1;
  DFS(0,-1);
  if(!Flag)
    cout<<0<<endl;
  else
    for(int i=0;i<M;i++)
      cout<<Ans[Edge[i]].first+1<<' '<<Ans[Edge[i]].second+1<<endl;
  return 0;
}