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
const int MAX_N = 3000000;

int T;
string str;
string ans;
int dp[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		cin>>str;
		while(!ans.empty())	ans.pop_back();
		int idx = 0;
		for(idx = 0; idx<=((int)str.size()-1)/2; idx++){
			if(str[idx]!=str[(int)str.size()-1-idx]){
				break;
			}
		}
		if(idx>((int)str.size()-1)/2){
			cout<<str<<endl;
		}else{
			for(int i=idx; i<=(int)str.size()-1-idx; i++){
				ans.pb(str[i]);
				ans.pb('*');
			}
			ans.pop_back();
			int r = 0, p = 0;
			int l1 = 0, l2 = 0;
			for(int i=0; i<ans.size(); i++){
				if(i<=r)	dp[i] = min(dp[2*p-i], r-i);
				else dp[i] = 0;
				while(i-dp[i]-1>=0 && i+dp[i]+1<(int)ans.size() && ans[i-dp[i]-1]==ans[i+dp[i]+1])	dp[i]++;
				if(r<i+dp[i]){
					r = i+dp[i];
					p = i;
				}
				if(i-dp[i]==0){
					l1 = max(l1, dp[i]);
				}
				if(i+dp[i]==(int)ans.size()-1){
					l2 = max(l2, dp[i]);
				}
			}
			if(l1>l2){
				for(int i=0; i<idx; i++){
					printf("%c", str[i]);
				}
				for(int i=idx; i<=idx+l1; i++){
					printf("%c", str[i]);
				}
				for(int i=(int)str.size()-idx; i<str.size(); i++){
					printf("%c", str[i]);
				}
				printf("\n");
			}else{
				for(int i=0; i<idx; i++){
					printf("%c", str[i]);
				}
				for(int i=(int)str.size()-idx-1-l2; i<str.size(); i++){
					printf("%c", str[i]);
				}
				printf("\n");
			}
		}

	}
	return 0;
}