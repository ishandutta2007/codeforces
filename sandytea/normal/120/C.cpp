//program 120C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int N,K;cin>>N>>K;
  int Ans=0;for(int i=0;i<N;i++){int X;cin>>X;Ans+=(X<=K*3)?(X%K):(X-K*3);}
  cout<<Ans<<endl;
  return 0;
}