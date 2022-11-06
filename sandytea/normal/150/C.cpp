//program 150C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct QueryType
{
  double Sum,LMax,RMax,Max;
};

double X[150000],Data[150000];
QueryType A[600000];

QueryType Update(QueryType X,QueryType Y)
{
  QueryType T;
  T.Sum=X.Sum+Y.Sum;
  T.LMax=max(X.LMax,X.Sum+Y.LMax);
  T.RMax=max(Y.RMax,Y.Sum+X.RMax);
  T.Max=max(max(X.Max,Y.Max),X.RMax+Y.LMax);
  return T;
}

void BuildTree(int P,int L,int R)
{
  if(L==R)
    A[P].LMax=A[P].RMax=A[P].Max=max(A[P].Sum=Data[L],0.0);
  else
    {
      int Mid=(L+R)/2;
      BuildTree(P*2,L,Mid);
      BuildTree(P*2+1,Mid+1,R);
      A[P]=Update(A[P*2],A[P*2+1]);
    }
}

QueryType Query(int P,int Left,int Right,int L,int R)
{
  if(Left==L&&Right==R)return A[P];
  int Mid=(Left+Right)/2;
  if(R<=Mid)return Query(P*2,Left,Mid,L,R);
  if(L>Mid)return Query(P*2+1,Mid+1,Right,L,R);
  return Update(Query(P*2,Left,Mid,L,Mid),Query(P*2+1,Mid+1,Right,Mid+1,R));
}

int main()
{
  int N,M;double C;cin>>N>>M>>C;N--;
  for(int i=0;i<=N;i++)cin>>X[i];
  for(int i=0;i<N;i++){double P;cin>>P;Data[i]=(X[i+1]-X[i])/2-P/100*C;}
  BuildTree(1,0,N-1);
  double Ans=0;
  while(M--){int L,R;cin>>L>>R;Ans+=Query(1,0,N-1,L-1,R-2).Max;}
  printf("%0.10lf\n",Ans);
  return 0;
}