//program 103A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;long long Ans=0;
  for(int i=0;i<N;i++)
    {
      long long X;cin>>X;
      Ans=Ans+(X-1)*(i+1)+1;
    }
  cout<<Ans<<endl;
  return 0;
}