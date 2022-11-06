//program 102B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

string Sum(string S)
{
  int T=0;for(int i=0;i<S.size();i++)T+=S[i]-48;
  string SS;while(T){SS+=T%10+48;T/=10;}
  return SS;
}

int main()
{
  string S;cin>>S;
  int Ans=0;
  while(S.size()>1){S=Sum(S);Ans++;}
  cout<<Ans<<endl;
  return 0;
}