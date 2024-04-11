//program 138E

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string S;
int A[100001],Count[100001];
int Sum[100001][26];

int main()
{
  cin>>S;int Len=S.size();
  for(int i=1;i<=Len;i++)A[i]=S[i-1]-97;
  memset(Sum,0,sizeof(Sum));
  for(int i=1;i<=Len;i++)
    for(int j=0;j<26;j++)
      Sum[i][j]=Sum[i-1][j]+(A[i]==j);
  int N,LB,UB;cin>>N>>LB>>UB;
  int W[500],Min[500],Max[500];
  for(int i=0;i<N;i++)
    {
      char c;while(c=getchar(),c<'a'||c>'z');
      W[i]=c-97;cin>>Min[i]>>Max[i];
    }
  long long Ans=0,Current=0;
  int L[500],R[500];for(int i=0;i<N;i++)L[i]=R[i]=1;
  memset(Count,0,sizeof(Count));
  for(int i=1;i<=Len;i++)
    {
      if(!LB)Current++;
      for(int j=0;j<N;j++)
        {
          while(R[j]<=i&&Sum[i][W[j]]-Sum[R[j]-1][W[j]]>=Min[j])
            {
              Count[R[j]]++;
              if(Count[R[j]]==LB)Current++;
              if(Count[R[j]]==UB+1)Current--;
              R[j]++;
            }
          while(L[j]<R[j]&&Sum[i][W[j]]-Sum[L[j]-1][W[j]]>Max[j])
            {
              Count[L[j]]--;
              if(Count[L[j]]==LB-1)Current--;
              if(Count[L[j]]==UB)Current++;
              L[j]++;
            }
        }
      Ans+=Current;
    }
  cout<<Ans<<endl;
  return 0;
}