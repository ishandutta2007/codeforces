//program 139C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string Get(int K)
{
  string S,T;cin>>S;T="";
  int Len=S.size(),Count=0;
  while(Len--&&Count<K)
    {
      T=S[Len]+T;
      if(S[Len]=='a'||S[Len]=='e'||S[Len]=='i'||S[Len]=='o'||S[Len]=='u')Count++;
    }
  return (Count<K)?"!":T;
}

int main()
{
  int N,K,Ans=7;cin>>N>>K;
  for(int i=0;i<N;i++)
    {
      string S1=Get(K),S2=Get(K),S3=Get(K),S4=Get(K);
      if(S1=="!"||S2=="!"||S3=="!"||S4=="!")Ans=0;
      if(S1!=S2||S3!=S4)Ans&=6;
      if(S1!=S3||S2!=S4)Ans&=5;
      if(S1!=S4||S2!=S3)Ans&=3;
    }
  if(!Ans)cout<<"NO"<<endl;
  else if(Ans==1)cout<<"aabb"<<endl;
  else if(Ans==2)cout<<"abab"<<endl;
  else if(Ans==4)cout<<"abba"<<endl;
  else if(Ans==7)cout<<"aaaa"<<endl;
  return 0;
}