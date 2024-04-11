//program 146A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,A[50];cin>>N;
  for(int i=0;i<N;i++)
    {
      char c=getchar();
      while(c<'0'||c>'9')c=getchar();
      A[i]=c-48;
    }
  bool Ans=true;
  int S1=0,S2=0;
  for(int i=0;i<N;i++)if(A[i]!=4&&A[i]!=7)Ans=false;
  for(int i=0,j=N-1;i<j;i++,j--){S1+=A[i];S2+=A[j];}
  if(S1!=S2)Ans=false;
  cout<<(Ans?"YES":"NO")<<endl;
  return 0;
}