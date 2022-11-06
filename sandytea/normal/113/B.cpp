//program 113B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

const int P=19961021;

long long List[4000000];

int main()
{
  string S,Prefix,Suffix;cin>>S>>Prefix>>Suffix;
  int N=S.size(),M1=Prefix.size(),M2=Suffix.size();
  bool F1[2000],F2[2000];
  memset(F1,0,sizeof(F1));memset(F2,0,sizeof(F2));
  for(int i=0;i+M1<=N;i++)
    {
      F1[i]=true;
      for(int j=0;F1[i]&&j<M1;j++)
        F1[i]=(S[i+j]==Prefix[j]);
    }
  for(int i=0;i+M2<=N;i++)
    {
      F2[i+M2-1]=true;
      for(int j=0;F2[i+M2-1]&&j<M2;j++)
        F2[i+M2-1]=(S[i+j]==Suffix[j]);
    }
  long long Hash[2000];Hash[0]=S[0];for(int i=1;i<N;i++)Hash[i]=Hash[i-1]*P+S[i];
  long long Pow[2000];Pow[0]=1;for(int i=1;i<N;i++)Pow[i]=Pow[i-1]*P;
  int Total=0;
  for(int i=0;i<N;i++)
    for(int j=i;j<N;j++)
      if(F1[i]&&F2[j]&&j-i+1>=max(M1,M2))
        List[Total++]=i?(Hash[j]-Hash[i-1]*Pow[j-i+1]):Hash[j];
  sort(List,List+Total);
  int Ans=0;
  for(int i=0;i<Total;i++)
    if(!i||List[i]!=List[i-1])
      Ans++;
  cout<<Ans<<endl;
  return 0;
}