//program 258-A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  string S;
  cin>>S;
  int N=S.size(),Break=N-1;
  for(int i=0;i<S.size();i++)
    if(S[i]=='0')
      {
        Break=i;
        break;
      }
  for(int i=0;i<N;i++)
    if(i!=Break)
      putchar(S[i]);
  putchar('\n');
  return 0;
}