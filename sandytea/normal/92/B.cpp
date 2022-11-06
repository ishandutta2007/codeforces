//program 92B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int Ans=0,P=S.size()-1;
  while(P>0)
    if(S[P]=='0')
      {P--;Ans++;}
    else
      {
        while(P>=0&&S[P]=='1'){P--;Ans++;}
        Ans++;if(P>=0)S[P]='1';
      }
  cout<<Ans<<endl;
  return 0;
}