//program 115E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

long long Sum[500001],F[500001];
vector< pair<int,long long> > Edge[500001];
int Left[2000000],Right[2000000],Mid[2000000];
long long Max[2000000],Delta[2000000];

long long GetNumber()
{
  char c=getchar();while(c<'0'||c>'9')c=getchar();
  long long X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void BuildTree(int P,int L,int R)
{
  Left[P]=L;Right[P]=R;Mid[P]=(L+R)/2;Max[P]=Delta[P]=0;
  if(L<R)
    {
      BuildTree(P*2,L,Mid[P]);
      BuildTree(P*2+1,Mid[P]+1,R);
    }
}

void Check(int P)
{
  if(Delta[P]==0)return;
  Max[P]+=Delta[P];
  if(Left[P]<Right[P]){Delta[P*2]+=Delta[P];Delta[P*2+1]+=Delta[P];}
  Delta[P]=0;
}

void Add(int P,int L,int R,long long D)
{
  Check(P);
  if(L==Left[P]&&R==Right[P]){Delta[P]+=D;return;}
  if(R<=Mid[P])Add(P*2,L,R,D);
  else if(L>Mid[P])Add(P*2+1,L,R,D);
  else{Add(P*2,L,Mid[P],D);Add(P*2+1,Mid[P]+1,R,D);}
  Check(P*2);Check(P*2+1);Max[P]=max(Max[P*2],Max[P*2+1]);
}

long long GetMax(int P,int L,int R)
{
  Check(P);
  if(L==Left[P]&&R==Right[P])return Max[P];
  if(R<=Mid[P])return GetMax(P*2,L,R);
  if(L>Mid[P])return GetMax(P*2+1,L,R);
  return max(GetMax(P*2,L,Mid[P]),GetMax(P*2+1,Mid[P]+1,R));
}

int main()
{
  int N=GetNumber(),M=GetNumber();
  Sum[0]=0;for(int i=1;i<=N;i++)Sum[i]=Sum[i-1]+GetNumber();
  while(M--)
    {
      int X=GetNumber(),Y=GetNumber();long long W=GetNumber();
      Edge[Y].push_back(make_pair(X,W));
    }
  BuildTree(1,0,N);F[0]=0;
  for(int i=1;i<=N;i++)
    {
      F[i]=F[i-1];
      for(int j=0;j<Edge[i].size();j++)
        Add(1,0,Edge[i][j].first-1,Edge[i][j].second);
      F[i]=max(F[i-1],GetMax(1,0,i-1)-Sum[i]);
      Add(1,i,i,F[i]+Sum[i]);
    }
  cout<<F[N]<<endl;
  return 0;
}