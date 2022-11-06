//program 161A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
  int Size,Number;
};

int main()
{
  int N,M,L,R;cin>>N>>M>>L>>R;
  Data A[100000];for(int i=0;i<N;i++){cin>>A[i].Size;A[i].Number=i+1;}
  Data B[100000];for(int i=0;i<M;i++){cin>>B[i].Size;B[i].Number=i+1;}
  int P=0,Q=0,Ans=0,S[100000],T[100000];
  while(P<N&&Q<M)
    if(B[Q].Size>=A[P].Size-L&&B[Q].Size<=A[P].Size+R)
      {S[Ans]=A[P++].Number;T[Ans]=B[Q++].Number;Ans++;}
    else if(B[Q].Size<A[P].Size-L)Q++;
    else if(B[Q].Size>A[P].Size+R)P++;
  cout<<Ans<<endl;
  for(int i=0;i<Ans;i++)cout<<S[i]<<' '<<T[i]<<endl;
  return 0;
}