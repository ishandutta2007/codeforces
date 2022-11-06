//program 93D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int Mod=1000000007;

long long Pow(long long T)
{
  if(!T)return 1;
  long long S=Pow(T/2);
  S=S*S%Mod;if(T&1)S=S*3%Mod;
  return S;
}

long long PowSum(long long T)
{
  if(!T)return 1;
  long long S=(Pow(T/2+1)+1)*PowSum(T/2)%Mod;
  if(!(T&1))S-=Pow(T+1);if(S<0)S+=Mod;
  return S;
}

long long GetSum(long long N)
{
  if(N==1)return 4;
  if(N==2)return 12;
  return (8*PowSum(N/2-1)+14*PowSum((N-3)/2)+4)%Mod;
}

long long GetAns(long long N)
{
  if(!N)return 0;
  long long Ans=(GetSum(N)+GetSum((N+1)/2))%Mod;
  return (Ans&1)?((Ans+Mod)/2):(Ans/2);
}

int main()
{
  long long LB,UB;cin>>LB>>UB;
  long long Ans=GetAns(UB)-GetAns(LB-1);
  cout<<((Ans<0)?(Ans+Mod):Ans)<<endl;
  return 0;
}