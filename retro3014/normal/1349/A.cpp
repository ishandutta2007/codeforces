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
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1;
const int MAX_K = 200000;

int N;

int num1[MAX_K+1], num2[MAX_K+1];
int cnt[MAX_K+1];

ll multi(ll x, ll y){
	if(y==0)	return 1;
	if(y==1)	return x;
	ll m = multi(x, y/2);
	if(y%2)	return (m*m*x);
	return (m*m);
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=200000; i++){
		num1[i] = num2[i] = INF;
	}
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		for(int j=2; j*j<=x; j++){
			if(x%j==0){
				int c = 0;
				while(x%j==0){
					x/=j;
					c++;
				}
				if(num1[j]>c){
					num2[j] = num1[j];
					num1[j] = c;
				}else if(num2[j]>c){
					num2[j] = c;
				}
				cnt[j]++;
			}
		}
		if(x!=0){
			cnt[x]++;
			if(num1[x]>1){
				num2[x] = num1[x];
				num1[x] = 1;
			}else if(num2[x]>1){
				num2[x] = 1;
			}
		}
	}
	ll ans = 1LL;
	for(int i=1; i<=200000; i++){
		if(cnt[i]==N){
			ans = ans * multi((ll)i, num2[i]);
		}else if(cnt[i]==N-1){
			ans = ans * multi((ll)i, num1[i]);
		}
	}
	cout<<ans;
	return 0;
}