//program 148A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int A,B,C,D,N,Ans=0;
  cin>>A>>B>>C>>D>>N;
  for(int i=1;i<=N;i++)if(i%A==0||i%B==0||i%C==0||i%D==0)Ans++;
  cout<<Ans<<endl;
  return 0;
}