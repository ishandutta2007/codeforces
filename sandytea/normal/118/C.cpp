//program 118C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

int Count[10];

int Get(int K,int X)
{
  int Sum=0,T;
  for(int i=0;K>0&&i<10;i++)
    {
      if(X-i>=0){T=min(K,Count[X-i]);K-=T;Sum+=T*i;}
      if(i&&X+i<10){T=min(K,Count[X+i]);K-=T;Sum+=T*i;}
    }
  return (K>0)?inf:Sum;
}

int main()
{
  int N,K;string S;cin>>N>>K>>S;
  int A[10000];for(int i=0;i<N;i++)A[i]=S[i]-48;
  int Ans=inf;string Best;
  for(int i=0;i<10;i++)
    {
      memset(Count,0,sizeof(Count));
      for(int j=0;j<N;j++)Count[A[j]]++;
      int Sum=Get(K,i),Current=Sum,Total=K;string Number;
      for(int j=0;j<N;j++)
        {
          Count[A[j]]--;int Digit=A[j];
          if(i>A[j]&&Get(Total,i)>Current)Digit=i;
          if(i<=A[j]&&Get(Total-1,i)+A[j]-i==Current)Digit=i;
          if(Digit==i){Total--;Current-=abs(i-A[j]);}
          Number+=Digit+48;
        }
      if(Sum<Ans||(Sum==Ans&&Number<Best)){Ans=Sum;Best=Number;}
    }
  cout<<Ans<<endl<<Best<<endl;
  return 0;
}