//program 125B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  int Total=0;
  for(int i=0;i<S.size();i++)
    if(S[i]>='a'&&S[i]<='z')
      {
        if(S[i-1]=='/')Total--;
        for(int j=0;j<Total*2;j++)putchar(' ');
        putchar('<');
        if(S[i-1]=='/')putchar('/');
        putchar(S[i]);
        putchar('>');
        putchar('\n');
        if(S[i-1]=='<')Total++;
      }
  return 0;
}