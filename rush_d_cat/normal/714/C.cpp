#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 1000005
typedef __int64 ll;
map<ll, ll> mp;
int val[20];
void add(ll x,ll a)
{
	int len=0;
	while(x>=0){
		val[++len]= (x%10)%2;
		x /= 10;
		if(x==0) break;
	}
	ll tmp=0;
	while(len>0){
		tmp*=10;
		tmp+=val[len--];
	}
	mp[tmp] += a;
}

int main()
{
	int t;cin>>t;
	while(t--){
		char op;ll tmp;
		cin>>op>>tmp;
		if(op=='+') add(tmp,1);
		if(op=='-') add(tmp,-1);
		if(op=='?') cout<<mp[tmp]<<endl;
	}
}