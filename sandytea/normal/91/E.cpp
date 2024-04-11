//program 91E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Line
{
  double T,K;
};

struct Data
{
  int Number;
  double Value;
};

bool operator <(Data A,Data B)
{
  return A.Value<B.Value;
}

const double inf=1e18;

Line A[100000];
int Left[300000],Right[300000],Mid[300000];
vector<int> List[300000];

double Calc(int Data,double Time)
{
  return Time*A[Data].K+A[Data].T;
}

double Cross(int X,int Y)
{
  return -(A[X].T-A[Y].T)/(A[X].K-A[Y].K);
}

void Add(int P,int New)
{
  int Top=List[P].size()-1;
  if(Top<1){List[P].push_back(New);return;}
  while(Top>=1)
    {
      double X=Cross(List[P][Top],New);
      if(Calc(New,X)>=Calc(List[P][Top-1],X))break;
      Top--;
    }
  Top++;List[P].resize(Top+1);List[P][Top]=New;
}

void BuildTree(int P,int L,int R)
{
  Left[P]=L;Right[P]=R;Mid[P]=(L+R)/2;
  if(L==R)
    List[P].push_back(L);
  else
    {
      BuildTree(P*2,L,Mid[P]);
      BuildTree(P*2+1,Mid[P]+1,R);
      int P1=0,P2=0;
      while(P1<List[P*2].size()||P2<List[P*2+1].size())
        if(P1==List[P*2].size())
          Add(P,List[P*2+1][P2++]);
        else if(P2==List[P*2+1].size())
          Add(P,List[P*2][P1++]);
        else if(A[List[P*2][P1]].K==A[List[P*2+1][P2]].K)
          if(A[List[P*2][P1]].T<A[List[P*2+1][P2]].T)P1++;else P2++;
        else if(A[List[P*2][P1]].K<A[List[P*2+1][P2]].K)
          Add(P,List[P*2][P1++]);
        else if(A[List[P*2][P1]].K>A[List[P*2+1][P2]].K)
          Add(P,List[P*2+1][P2++]);
    }
}

Data Get(int P,double Time)
{
  int Left=0,Right=List[P].size()-1;
  while(true)
    {
      int Mid=(Left+Right)/2;
      double L=Mid?Cross(List[P][Mid-1],List[P][Mid]):-inf;
      double R=(Mid==List[P].size()-1)?inf:Cross(List[P][Mid],List[P][Mid+1]);
      if(L<=Time&&Time<=R)return (Data){List[P][Mid]+1,Calc(List[P][Mid],Time)};
      if(Time>R)Left=Mid+1;else Right=Mid-1;
    }
}

Data Query(int P,int L,int R,double Time)
{
  if(L==Left[P]&&R==Right[P])return Get(P,Time);
  if(R<=Mid[P])return Query(P*2,L,R,Time);
  if(L>Mid[P])return Query(P*2+1,L,R,Time);
  return max(Query(P*2,L,Mid[P],Time),Query(P*2+1,Mid[P]+1,R,Time));
}

int main()
{
  int N,M;cin>>N>>M;
  for(int i=0;i<N;i++)cin>>A[i].T>>A[i].K;
  BuildTree(1,0,N-1);
  while(M--)
    {
      int X,Y,T;cin>>X>>Y>>T;X--;Y--;
      cout<<Query(1,X,Y,T).Number<<endl;
    }
  return 0;
}