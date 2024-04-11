//program 133B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  char c;int Ans=0;
  while(scanf("%c",&c)!=EOF&&(c=='>'||c=='<'||c=='+'||c=='-'||c=='.'||c==','||c=='['||c==']'))
    {
      Ans*=16;
      if(c=='>')Ans+=8;
      if(c=='<')Ans+=9;
      if(c=='+')Ans+=10;
      if(c=='-')Ans+=11;
      if(c=='.')Ans+=12;
      if(c==',')Ans+=13;
      if(c=='[')Ans+=14;
      if(c==']')Ans+=15;
      Ans%=1000003;
    }
  cout<<Ans<<endl;
  return 0;
}