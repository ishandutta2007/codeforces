//program 133A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  bool Ans=false;char c;
  while(scanf("%c",&c)!=EOF)Ans=Ans||(c=='H')||(c=='Q')||(c=='9');
  printf(Ans?"YES\n":"NO\n");
  return 0;
}