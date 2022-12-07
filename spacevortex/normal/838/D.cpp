#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
int n,m;
int main()
{
	cin>>n>>m;
	cout<<mul(power(2*n+2,m),mul(n+1-m,inv(n+1)));
	return 0;
}