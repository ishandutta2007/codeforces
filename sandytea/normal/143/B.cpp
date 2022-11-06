//program 143B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int Len=0;char c,S[100];
  while(scanf("%c",&c)!=EOF&&c!=10)S[Len++]=c;
  int p=Len;
  for(int i=0;i<Len;i++)if(S[i]=='.')p=i;
  string Ans="$";
  for(int i=0;i<p;i++)
    if(S[i]!='-')
      {
        Ans+=S[i];
        if((p-i)%3==1&&i!=p-1)Ans+=',';
      }
  Ans+='.';
  if(++p<Len)Ans+=S[p];else Ans+='0';
  if(++p<Len)Ans+=S[p];else Ans+='0';
  if(S[0]=='-')Ans='('+Ans+')';
  cout<<Ans<<endl;
  return 0;
};