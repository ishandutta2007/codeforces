//program 110B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  for(int i=0;i<N;i++)putchar(i%4+97);
  putchar('\n');
  return 0;
}