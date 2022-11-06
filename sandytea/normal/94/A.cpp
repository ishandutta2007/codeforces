//program 94A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;cin>>S;
  string T[10];for(int i=0;i<10;i++)cin>>T[i];
  for(int i=0;i<8;i++)
    {
      string Tmp;
      for(int j=0;j<10;j++)Tmp+=S[i*10+j];
      for(int j=0;j<10;j++)if(T[j]==Tmp)cout<<j;
    }
  putchar('\n');
  return 0;
}