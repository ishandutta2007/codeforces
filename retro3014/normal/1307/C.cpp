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
const int MAX_K = 30;

string str;
ll cnt[MAX_K+1];
ll cnt2[MAX_K+1][MAX_K+1];
ll ans;

int main(){
	cin>>str;
	for(int i=0; i<str.size(); i++){
		for(int j=0; j<='z'-'a'; j++){
			cnt2[j][str[i]-'a']+=cnt[j];
			ans = max(ans, cnt2[j][str[i]-'a']);
		}
		cnt[str[i]-'a']++;
		ans = max(ans, cnt[str[i]-'a']);
	}
	cout<<ans;
	return 0;
}