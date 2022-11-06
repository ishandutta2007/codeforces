//program 136A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,Ans[101];cin>>N;
  for(int i=1;i<=N;i++){int X;cin>>X;Ans[X]=i;}
  for(int i=1;i<N;i++)cout<<Ans[i]<<' ';
  cout<<Ans[N]<<endl;
  return 0;
}