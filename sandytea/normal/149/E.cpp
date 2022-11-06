//program 149E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int inf=1000000000;

string S1,S2,T1,T2;
int Next[1001],Min[1001],Prefix[1001],Suffix[1001];

string Reverse(string S)
{
  string T;
  for(int i=S.size()-1;i>=0;i--)T+=S[i];
  return T;
}

int main()
{
  cin>>S1;S2=Reverse(S1);
  int N=S1.size(),Total,Ans=0;cin>>Total;
  while(Total--)
    {
      cin>>T1;T2=Reverse(T1);
      int M=T1.size(),P=Next[0]=0;
      for(int i=1;i<M;i++)
        {
          while(P&&T1[P]!=T1[i])P=Next[P-1];
          if(T1[P]==T1[i])P++;Next[i]=P;
        }
      for(int i=0;i<=M;i++)Min[i]=inf;
      for(int i=P=0;i<N;i++)
        {
          while(P&&S1[i]!=T1[P])P=Next[P-1];if(S1[i]==T1[P])P++;
          Min[P]=min(Min[P],i+1-P);if(P==M)P=Next[M-1];
        }
      Prefix[M]=Min[M];for(int i=M-1;i>=0;i--)Prefix[i]=min(Prefix[i+1],Min[i]);
      P=Next[0]=0;
      for(int i=1;i<M;i++)
        {
          while(P&&T2[P]!=T2[i])P=Next[P-1];
          if(T2[P]==T2[i])P++;Next[i]=P;
        }
      for(int i=0;i<=M;i++)Min[i]=inf;
      for(int i=P=0;i<N;i++)
        {
          while(P&&S2[i]!=T2[P])P=Next[P-1];if(S2[i]==T2[P])P++;
          Min[P]=min(Min[P],i+1-P);if(P==M)P=Next[M-1];
        }
      Suffix[M]=Min[M];for(int i=M-1;i>=0;i--)Suffix[i]=min(Suffix[i+1],Min[i]);
      bool Flag=false;
      for(int i=1;i<M;i++)if(Prefix[i]+Suffix[M-i]+M<=N)Flag=true;
      if(Flag)Ans++;
    }
  cout<<Ans<<endl;
  return 0;
}