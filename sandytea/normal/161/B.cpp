//program 161B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Data
{
  long long Price;
  int Type,Number;
};

bool operator <(Data A,Data B)
{
  return A.Price>B.Price;
}

int main()
{
  int N,K;cin>>N>>K;
  Data A[1000];for(int i=0;i<N;i++){cin>>A[i].Price>>A[i].Type;A[i].Number=i+1;}
  int Cart[1000];for(int i=0;i<N;i++)Cart[i]=-1;
  int Count=0;long long Ans=0;sort(A,A+N);
  for(int i=0;i<N&&Count<K-1;i++)
    if(A[i].Type==1)
      {Cart[i]=Count++;Ans-=A[i].Price;}
  bool Flag=false;
  for(int i=0;i<N;i++)
    if(Cart[i]==-1)
      {Cart[i]=Count;if(Count<K-1)Count++;if(A[i].Type==1)Flag=true;}
  if(Flag)Ans-=A[N-1].Price;
  for(int i=0;i<N;i++)Ans+=A[i].Price*2;
  cout<<Ans/2<<((Ans&1)?".5":".0")<<endl;
  vector<int> List[1000];
  for(int i=0;i<N;i++)List[Cart[i]].push_back(A[i].Number);
  for(int i=0;i<K;i++)
    {
      cout<<List[i].size();
      for(int j=0;j<List[i].size();j++)
        cout<<' '<<List[i][j];
      putchar('\n');
    }
  return 0;
}