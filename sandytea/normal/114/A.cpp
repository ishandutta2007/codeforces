//program 114A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  long long K,N;cin>>K>>N;
  long long T=K;int Ans=0;
  while(T<N){T*=K;Ans++;}
  if(T==N)cout<<"YES"<<endl<<Ans<<endl;else cout<<"NO"<<endl;
  return 0;
}