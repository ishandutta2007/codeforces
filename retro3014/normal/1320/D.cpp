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
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 200010;
const ll P1 = 1000000007;
const ll P2 = 998244353;
const int MAX_K = 20;

int N, Q;
int num[MAX_N+1];
string str;
vector<int> v;
set<int> st;
pll dp[MAX_N+1][MAX_K+1];
int nxt[MAX_N+1][MAX_K+1];
pll two[MAX_K+1];

int main(){
	scanf("%d", &N);
	cin>>str;
	str.pb('0');
	two[0] = {1LL, 1LL};
	two[1] = {2LL, 2LL};
	for(int i=2; i<=MAX_K; i++){
		two[i] = {(two[i-1].first*two[i-1].first)%P1, (two[i-1].second*two[i-1].second)%P2};
	}
	for(int i=0; i<MAX_K; i++)	nxt[N+1][i] = N+1;
	for(int i=N; i>=1; i--){
		str[i] = str[i-1];
		if(str[i]=='0'){
			if(!v.empty()){
				nxt[i][0] = v.back();
				dp[i][0] = {(ll)(v.back()-i-1)%2LL, (ll)(v.back()-i-1)%2LL};
			}else{
				nxt[i][0] = N+1;
			}
			for(int k=1; k<MAX_K; k++){
				nxt[i][k] = nxt[nxt[i][k-1]][k-1];
				if(nxt[i][k]==N+1)	continue;
				dp[i][k] = {((dp[i][k-1].first*two[k].first%P1)+dp[nxt[i][k-1]][k-1].first) % P1, ((dp[i][k-1].second*two[k].second%P2)+dp[nxt[i][k-1]][k-1].second) % P2};
			}
			v.pb(i);
			st.insert(i);
		}
	}
	sort(v.begin(), v.end());
	scanf("%d", &Q);
	for(int i=1; i<=N; i++){
		num[i] = num[i-1] + (str[i]=='0');
	}
	while(Q--){
		int s1, e1, s2, e2, len;
		scanf("%d%d%d", &s1, &s2, &len);
		e1 = s1+len-1; e2 = s2+len-1;
		int cnt = num[e1]-num[s1-1];
		if(cnt!=num[e2]-num[s2-1]){
			printf("NO\n");
			continue;
		}if(cnt==0){
			printf("YES\n");
			continue;
		}
		int n1 = (*(st.lower_bound(s1))), n2 = (*(st.lower_bound(s2)));
		TEST cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<" "<<n1<<" "<<n2<<endl;
		cnt--;
		//cout<<cnt<<endl;
		if((n1-s1)%2!=(n2-s2)%2){
			printf("NO\n");
			continue;
		}
		bool fin = false;
		for(int i=MAX_K-1; i>=0; i--){
			if((1<<i)<=cnt){
				//cout<<i<<endl;
				if(dp[n1][i].first!=dp[n2][i].first || dp[n1][i].second!=dp[n2][i].second){
					printf("NO\n");
					fin = true;
					break;
				}
				n1 = nxt[n1][i]; n2 = nxt[n2][i];
				cnt-=(1<<i);
			}
		}
		TEST cout<<n1<<" "<<n2<<endl;
		if(fin)	continue;
		if((e1-n1)%2!=(e2-n2)%2){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}

	return 0;
}