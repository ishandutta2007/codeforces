#include <bits/stdc++.h>

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(x) x.begin(),x.end()

using namespace std;

using pi=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

void print(int x,int z){
	printf("%lld",x);
	if(z==1)printf("\n");
	if(z==2)printf(" ");
}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

signed main(){
	int n=read();
	map<pi,vi> w;
	REP(i,n){
		int a,b,c;
		scanf("%*c(%lld+%lld)/%lld",&a,&b,&c);
		a+=b;
		int g=gcd(a,c);
		a/=g;
		c/=g;
		w[pi(a,c)].PB(i);
	}
	vi ans(n);
	for(auto kv:w){
		int s=kv.second.size();
		for(auto i:kv.second)
			ans[i]=s;
	}
	REP(i,n)
		print(ans[i],i==n-1?1:2);
}