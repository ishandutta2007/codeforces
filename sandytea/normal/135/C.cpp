//program 135C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;

int main()
{
  cin>>S;int N=S.size(),M=N/2;
  int S0=0;for(int i=0;i<N;i++)if(S[i]=='0')S0++;
  int S1=0;for(int i=0;i<N;i++)if(S[i]=='1')S1++;
  if(N%2)
    {
      if(S1<=M)cout<<"00"<<endl;
      if(S[N-1]=='1'&&S0<=M&&S1<=M+1)cout<<"01"<<endl;
      if(S[N-1]=='?'&&S0<=M&&S1<=M)cout<<"01"<<endl;
      if(S[N-1]=='0'&&S0<=M&&S1<=M+1)cout<<"10"<<endl;
      if(S[N-1]=='?'&&S0<M&&S1<=M+1)cout<<"10"<<endl;
      if(S0<M)cout<<"11"<<endl;
    }
  else
    {
      if(S1<M)cout<<"00"<<endl;
      if(S[N-1]=='1'&&S0<=M&&S1<=M)cout<<"01"<<endl;
      if(S[N-1]=='?'&&S0<=M&&S1<M)cout<<"01"<<endl;
      if(S[N-1]=='0'&&S0<=M&&S1<=M)cout<<"10"<<endl;
      if(S[N-1]=='?'&&S0<M&&S1<=M)cout<<"10"<<endl;
      if(S0<M)cout<<"11"<<endl;
    }
  return 0;
}