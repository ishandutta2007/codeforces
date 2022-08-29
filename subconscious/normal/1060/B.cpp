#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp pake_pair
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucksm
#define y1 fucklzw
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
ll n;
int s(ll x){
	int ret=0;
	while(x)ret+=x%10,x=x/10;
	return ret;
}
int main(){
	scanf("%lld",&n);
	ll s1=0;
	while(s1*10+9<=n)s1=s1*10+9;
	ll s2=n-s1;
	printf("%d\n",s(s1)+s(s2));
	return 0;
}