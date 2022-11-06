//program 115C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> A;
string S;

int main()
{
  int M,N;cin>>M>>N;
  for(int i=0;i<M;i++){cin>>S;A.push_back(S);}
  int Ans=1;
  for(int i=0;i<M;i++)
    {
      bool Flag=true,T;
      for(int j=0;j<N;j++)
        if(A[i][j]!='.')
          {
            bool F=(A[i][j]=='1'||A[i][j]=='2')^(j&1);
            if(Flag){Flag=false;T=F;}
            if(T^F)Ans=0;
          }
      if(Flag)Ans=Ans*2%1000003;
    }
  for(int j=0;j<N;j++)
    {
      bool Flag=true,T;
      for(int i=0;i<M;i++)
        if(A[i][j]!='.')
          {
            bool F=(A[i][j]=='1'||A[i][j]=='4')^(i&1);
            if(Flag){Flag=false;T=F;}
            if(T^F)Ans=0;
          }
      if(Flag)Ans=Ans*2%1000003;
    }
  cout<<Ans<<endl;
  return 0;
}