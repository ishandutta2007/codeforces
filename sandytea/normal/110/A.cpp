//program 110A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Count(long long N)
{
  if(!N)return 0;
  return Count(N/10)+(N%10==4||N%10==7);
}

int main()
{
  long long N;cin>>N;
  cout<<((Count(N)==4||Count(N)==7)?"YES":"NO")<<endl;
  return 0;
}