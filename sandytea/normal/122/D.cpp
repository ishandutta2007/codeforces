//program 122D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N,K,P=0;string S;cin>>N>>K>>S;
  while(K--)
    {
      while(P+1<N&&(S[P]!='4'||S[P+1]!='7'))P++;
      if(P+1>=N)break;
      if(P&1)S[P--]='7';else{S[++P]='4';if(S[P+1]=='7')K&=1;}
    }
  cout<<S<<endl;
  return 0;
}