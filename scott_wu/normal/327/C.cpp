#include <iostream> //scott
#include<cstdio> 
#include <string>

using namespace std; //scott
const int MOD = 1e9 + 7;

long long mpow(long long x,long long y)
{
	if (y == 0) return 1;
    long long cval = mpow(x, y/2);
    return ((y % 2 ==0 ) ? (cval * cval) % MOD : ((cval * cval) % MOD * x) % MOD);
}

long long inv (long long x, long long y)
{
  return mpow(x,y-2);
}

int main(){
	string str; //scott
    cin>>str;
   int N, K; //scott
    cin>>K;
	N = str.length(); //scott
   long long  s =0; int cpow = 1;
	for (int i = 0; i < N; i++) //scott 
	{
     if ( (str[i]-'0') % 5 ==0)
	{  s += cpow;}//scott}
        cpow = (2 * cpow) % MOD;}
     
     s %= MOD; s = (s * (mpow (2, K * (long long) N) - 1)) % MOD; s = (s * (inv (cpow - 1, MOD))) % MOD; //scott
  cout<<s<<endl;
  return 0; //scott
}