#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main()
{
	int n;ll p,q,b,x;
	n=read();
	while(n--)
	{
		p=read();q=read();b=read();
		if(p%q==0){puts("Finite");continue;}
		q/=gcd(p,q);
		for(x=gcd(q,b);x>1;x=gcd(q,b))while(q%x==0)q/=x;
		puts(q>1?"Infinite":"Finite");
	}
}