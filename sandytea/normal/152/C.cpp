//program 152C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
  int M,N;cin>>M>>N;
  set<int> Letter[100];
  for(int i=0;i<M;i++)
    {
      string S;cin>>S;
      for(int j=0;j<N;j++)Letter[j].insert(S[j]);
    }
  long long Ans=1;
  for(int i=0;i<N;i++)Ans=Ans*Letter[i].size()%1000000007;
  cout<<Ans<<endl;
  return 0;
}