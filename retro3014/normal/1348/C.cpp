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
const int MAX_C = 26;
int T, N, K;
string str;
int cnt[MAX_C+1], cnt2[MAX_C+1];
string ans;

bool chk(){
	ll num = 0;
	ll sum = 0;
	for(int i=0; i<MAX_C; i++){
		num=(ll)cnt2[i]*(ll)K;
		sum+=(ll)cnt[i];
		sum-=min(num, sum);
	}

	return (sum==0);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		cin>>str;
		sort(str.begin(), str.end());
		while(!ans.empty())	ans.pop_back();
		bool tf = false;
		for(int i=0; i<K; i++){
			if(str[i]!=str[0]){
				//cout<<i<<endl;
				ans.pb(str[K-1]);
				cout<<ans<<endl;
				tf = true;
				break;
			}
		}
		if(tf)	continue;
		ans.pb(str[0]);
		if(K==N){
			cout<<ans<<endl;
			continue;
		}
		if(str[K]==str.back()){
			for(int i=K; i<str.size(); i+=K){
				ans.pb(str[i]);
			}
		}else{
			for(int i=K; i<str.size(); i++){
				ans.pb(str[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}