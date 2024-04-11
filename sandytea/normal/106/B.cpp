//program 106B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int main()
{
  int N;cin>>N;
  int P1[100],P2[100],P3[100],Price[100];
  for(int i=0;i<N;i++)cin>>P1[i]>>P2[i]>>P3[i]>>Price[i];
  bool Flag[100];memset(Flag,0,sizeof(Flag));
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
	  if(P1[i]<P1[j]&&P2[i]<P2[j]&&P3[i]<P3[j])
	    Flag[i]=true;
  int Min=inf,Ans;
  for(int i=0;i<N;i++)
    if(!Flag[i]&&Price[i]<Min)
	  {Min=Price[i];Ans=i+1;}
  cout<<Ans<<endl;
  return 0;
}