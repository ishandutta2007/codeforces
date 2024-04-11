#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7;
ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	ll mi=max(k-n,1ll),ma=min(k-1,min(n,(k-1)/2));
	printf("%lld\n",max(0ll,ma-mi+1));
}