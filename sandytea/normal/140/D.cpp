//program 140D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,T[100];
  cin>>N;for(int i=0;i<N;i++)cin>>T[i];sort(T,T+N);
  int Ans=0,Penalty=0,Sum=-350;
  while(Ans<N&&Sum+T[Ans]<=360)Penalty+=max(Sum+=T[Ans++],0);
  cout<<Ans<<' '<<Penalty<<endl;
  return 0;
}