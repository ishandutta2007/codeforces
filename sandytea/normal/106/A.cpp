//program 106A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

char Get()
{
  char c=getchar();
  while(c==' '||c==10)c=getchar();
  return c;
}

int Change(char c)
{
  if(c=='T')return 10;
  if(c=='J')return 11;
  if(c=='Q')return 12;
  if(c=='K')return 13;
  if(c=='A')return 14;
  return c-48;
}

int main()
{
  char Main=Get(),A1=Get(),B1=Get(),A2=Get(),B2=Get();
  cout<<(((B1==B2)?(Change(A1)>Change(A2)):(B1==Main))?"YES":"NO")<<endl;
  return 0;
}