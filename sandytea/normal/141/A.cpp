//program 141A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int Count[26];memset(Count,0,sizeof(Count));
  char c;
  while(c=getchar(),c!=10)Count[c-65]++;
  while(c=getchar(),c!=10)Count[c-65]++;
  while(c=getchar(),c!=10)Count[c-65]--;
  bool Ans=true;for(int i=0;i<26;i++)Ans=Ans&&!Count[i];
  printf(Ans?"YES\n":"NO\n");
  return 0;
};