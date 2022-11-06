//program 119D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string A,B,S;
int Prefix[2000001],Suffix[2000001];

int main()
{
  char c;while(c=getchar(),c!=10)A+=c;while(c=getchar(),c!=10)B+=c;
  if(A.size()!=B.size()){cout<<"-1 -1"<<endl;return 0;}
  int N=A.size();
  S="";for(int i=0;i<N;i++)S+=B[i];S+='\0';for(int i=0;i<N;i++)S+=A[i];
  int Left=0,Right=0;
  for(int i=1;i<=N*2;i++)
    if(i>Right)
      {
        Left=Right=i;while(Right<=N*2&&S[Right]==S[Right-Left])Right++;
        Prefix[i]=Right-Left;Right--;
      }
    else if(Prefix[i-Left]<Right-i+1)
      Prefix[i]=Prefix[i-Left];
    else
      {
        Left=i;while(Right<=N*2&&S[Right]==S[Right-Left])Right++;
        Prefix[i]=Right-Left;Right--;
      }
  S="";for(int i=N-1;i>=0;i--)S+=A[i];S+='\0';for(int i=0;i<N;i++)S+=B[i];
  Suffix[0]=0;
  for(int i=1;i<=N*2;i++)
    {
      Suffix[i]=Suffix[i-1];
      while(Suffix[i]&&S[i]!=S[Suffix[i]])Suffix[i]=Suffix[Suffix[i]-1];
      if(S[i]==S[Suffix[i]])Suffix[i]++;
    }
  int Ans_1=-1,Ans_2=-1;
  for(int i=0,Len=N-1;Len&&A[i]==B[Len];i++,Len--)
    {
      int T1=Prefix[N+i+2],T2=Suffix[N+Len];
      if(T1+T2>=Len){Ans_1=i;Ans_2=i+Len-T2+1;}
    }
  cout<<Ans_1<<' '<<Ans_2<<endl;
  return 0;
}