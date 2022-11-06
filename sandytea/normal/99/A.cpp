//program 99A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  char c,S[1000];int Len=0;
  while(c=getchar(),c!='.')S[Len++]=c;
  if(S[Len-1]=='9')
    cout<<"GOTO Vasilisa."<<endl;
  else
    {
      if(getchar()>='5')S[Len-1]++;
      for(int i=0;i<Len;i++)putchar(S[i]);
      putchar('\n');
    }
  return 0;
}