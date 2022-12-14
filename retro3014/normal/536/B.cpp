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
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000000;

int N, M;
string str;
vector<int> vt;
vector<int> chk;

ll cnt = 0;

ll multi(ll x, ll y){
	if(y==0)	return 1;
	if(y==1)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2){
		return ((m*m)%MOD)*x % MOD;
	}else{
		return (m*m)%MOD;
	}
}

ll prime = 37;
pll chk1[MAX_N+1], chk2[MAX_N+1];

bool pro(){
	ll sum1 = 0, sum2 = 0;
	for(int i=0; i<str.size(); i++){
		sum1 = (sum1 * prime + (int)(str[i] - 'a')) % MOD1;
		sum2 = (sum2 * prime + (int)(str[i] - 'a')) % MOD2;
		chk1[i+1] = {sum1, sum2};
	}
	sum1 = 0; sum2 = 0;
	ll m1 = 1, m2 = 1;
	for(int i=str.size()-1; i>=0; i--){
		sum1 = (sum1 + m1 * (int)(str[i]-'a')) % MOD1;
		sum2 = (sum2 + m2 * (int)(str[i]-'a')) % MOD2;
		chk2[str.size()-i] = {sum1, sum2};
		m1 = (m1 * prime) % MOD1;
		m2 = (m2 * prime) % MOD2;
	}
	for(int i=0; i<chk.size(); i++){
		if(chk1[chk[i]]!=chk2[chk[i]]){
			return false;
		}
	}
	return true;
	
}

int main(){
	scanf("%d%d", &N, &M);
	cin>>str;
	for(int i=0; i<M; i++){
		int x; scanf("%d", &x);
		vt.pb(x);
	}
	if(vt.empty())	cnt = N;
	else{
		cnt = vt[0] - 1;
		int prv = vt[0];
		for(int i=1; i<vt.size(); i++){
			if(vt[i] > prv + str.size() - 1){
				cnt += vt[i] - (prv + str.size()-1) - 1;
			}else{
				chk.pb(prv + str.size() - 1 - vt[i] + 1);
			}
			prv = vt[i];
		}
		cnt += N - (prv + str.size() - 1);
	}
	if(pro()){
		printf("%lld", multi(26, cnt));
	}else{
		printf("0");
	}
	return 0;
}