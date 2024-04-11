#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 0
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const ll INF = 1e9;
const ll INFLL = 4e18;
const int MAX_N = 100000;

int N;
ll K;
ll arr[MAX_N+1];

pll calc(ll x){
	pll p = {0LL, 0LL};
	for(int i=1; i<=N; i++){
		if(arr[i]<x)	continue;
		if(arr[i]==x){
			p.second++;
			continue;
		}
		ll bs = 0, be = INF, bm;
		while(bs<be){
			bm = (bs+be)/2LL+1LL;
			ll t = arr[i] - 3LL*bm*bm - 3LL*bm - 1LL;
			if(t>=x){
				bs = bm;
			}else{
				be = bm-1LL;
			}
		}
		if(bs+1LL>arr[i]){
			p.first+=arr[i];
			p.second+=arr[i];
			continue;
		}
		p.first+=bs+1LL;
		p.second+=bs+1LL;
		if(arr[i]-3LL*bs*bs-3LL*bs-1LL==x){
			p.first-=1LL;
		}
	}
	return p;
}

int main(){
	scanf("%d%lld", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
	}
	ll s = 0, e = INFLL+INF, m;
	ll c1=0, c2=0;
	while(s<e){
		m = (s+e)/2 - INFLL;
		pll p = calc(m);
		TEST cout<<m<<" "<<p.first<<" "<<p.second<<endl;
		c1 = p.first;
		c2 = p.second;
		if(c1<=K && K<=c2){
			s = e = m+INFLL;
			break;
		}else if(c2<K){
			e = m+INFLL-1LL;
		}else{
			s = m+INFLL+1LL;
		}
	}
	s-=INFLL;
	//cout<<s<<endl;
	pll p = calc(s);
	ll t = K - p.first;
	for(int i=1; i<=N; i++){
		if(arr[i]<s)	{
			printf("0 ");
			continue;
		}
		if(arr[i]==s){
			if(t>0){
				printf("1 ");
				t--;
			}else{
				printf("0 ");
			}
			continue;
		}
		ll bs = 0, be = INF, bm;
		while(bs<be){
			bm = (bs+be)/2LL+1LL;
			ll t = arr[i] - 3LL*bm*bm - 3LL*bm - 1LL;
			if(t>=s){
				bs = bm;
			}else{
				be = bm-1LL;
			}
		}
		if(bs+1LL>arr[i]){
			printf("%lld ", arr[i]);
			continue;
		}
		if(arr[i]-3LL*bs*bs-3LL*bs-1LL==s){
			if(t>0){
				printf("%lld ", bs+1LL);
				t--;
			}else{
				printf("%lld ", bs);
			}
		}else{
			printf("%lld ", bs+1LL);
		}
	}
	return 0;
}