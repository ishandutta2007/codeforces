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
const int MAX_N = 1000000;
const int MAX_K = 5000;
const int MAX_P = 700;

int cnt[MAX_K+1], sum[MAX_K+1];
int num[MAX_K+1][MAX_P+1];
vector<int> prime;
int c[MAX_N+1];
int N;

void init(){
	for(int i=2; i<=MAX_K; i++){
		bool tf = true;
		for(int j : prime){
			if(i%j==0){
				tf = false;
				break;
			}
			if(j*j>i)	break;
		}
		if(tf){
			prime.pb(i);
		}
	}
	for(int i=2; i<=MAX_K; i++){
		int n = i;
		sum[i]+=sum[i-1];
		for(int j=0; j<prime.size(); j++){
			while(n%prime[j]==0){
				num[i][j]++;
				sum[i]++;
				n/=prime[j];
			}
			num[i][j]+=num[i-1][j];
		}
		//cout<<i<<" "<<sum[i]<<endl;
	}
}

ll ans;

void solve(int x, int y){
	int s = prime[x], e = y, m;
	int p = prime[x], idx = x, C = 0, S = 0;
	while(1){
		S = 0;
		m = e+1;
		//cout<<s<<" "<<e<<" "<<p<<" "<<C<<endl;
		for(int i=e; i>=s; i--){
			if(num[i][idx]>=C+1){
				S += c[i];
				m = i;
			}
		}
		if(S>N/2){
			ans = ans + (ll)N - (ll)S * 2LL;
			s = m;
			C++;
		}else{
			if(idx==0)	break;
			e = m-1;
			idx--;
			p = prime[idx];
			C = 0;
		}
	}
}

int main(){
	init();
	//cout<<"*";
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		ans += (ll)sum[x];
		c[x]++;
	}
	int idx = 5000;
	for(int i=prime.size()-1; i>=0; i--){
		int p = prime[i];
		int cnt = 0;
		int s = idx;
		while(idx>=p){
			cnt+=c[idx];
			idx--;
		}
		if(cnt>N/2){
			solve(i, s);
			break;
		}
	}
	cout<<ans;
	return 0;
}