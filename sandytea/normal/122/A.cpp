//program 122A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool OK(int T)
{
  if(!T)return true;
  if(T%10!=4&&T%10!=7)return false;
  return OK(T/10);
}

int main()
{
  int N;cin>>N;
  bool Flag=false;for(int i=1;i*i<=N;i++)if(N%i==0)Flag=Flag||OK(i)||OK(N/i);
  cout<<(Flag?"YES":"NO")<<endl;
  return 0;
}