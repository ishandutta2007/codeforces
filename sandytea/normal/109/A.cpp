//program 109A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

void Output(int P,int N)
{
  for(int i=0;i<N;i++)putchar(P+48);
}

int main()
{
  int N;cin>>N;
  int M=-1;
  for(int i=0;i*7<=N;i++)
    if((N-i*7)%4==0)
      M=i;
  if(M==-1)
    cout<<-1<<endl;
  else
    {Output(4,(N-M*7)/4);Output(7,M);putchar('\n');}
  return 0;
}