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
const int MAX_N = 14;

int N;
int c[MAX_N+1][MAX_N+1];

vector<pair<pii, ll> > vt, v;
ll dp[MAX_N+1][(1<<(MAX_N+1))];
bool chk[MAX_N+1][(1<<(MAX_N+1))];
vector<pii> st;
vector<int> gp[2][MAX_N+1];

void dfs(int x){
	int sz = v.size();
	if(x==N){
		ll sum = 0;
		for(int i=0; i<vt.size(); i++){
			sum+=vt[i].second;
		}
		printf("%lld ", sum);
		return;
	}else{
		while(!vt.empty()){
			pair<pii, ll> now = vt.back(); vt.pop_back();
			v.pb(now);
			for(int i:gp[0][now.first.first]){
				if((now.first.second&(1<<i))==0){
					//c/out<<now.first.first<<" "<<now.first.second<<" "<<i<<endl;
					//cout<<c[now.first.first][i]<<endl;
					if(!chk[i][now.first.second+(1<<i)]){
						chk[i][now.first.second+(1<<i)] = true;
						st.pb({i, now.first.second+(1<<i)});
					}
					dp[i][now.first.second+(1<<i)]+=now.second;
				}
			}
		}
		while(!st.empty()){
			vt.pb({st.back(), dp[st.back().first][st.back().second]});
			chk[st.back().first][st.back().second] = false;
			dp[st.back().first][st.back().second] = 0;
			st.pop_back();
		}
		dfs(x+1);
		while(!vt.empty())	vt.pop_back();
		while(v.size()>sz)	{
			vt.pb(v.back());
			v.pop_back();
		}
		while(!vt.empty()){
			pair<pii, ll> now = vt.back(); vt.pop_back();
			v.pb(now);
			for(int i : gp[1][now.first.first]){
				if((now.first.second&(1<<i))==0){
					if(!chk[i][now.first.second+(1<<i)]){
						chk[i][now.first.second+(1<<i)] = true;
						st.pb({i, now.first.second+(1<<i)});
					}
					dp[i][now.first.second+(1<<i)]+=now.second;
				}
			}
		}
		while(!st.empty()){
			//cout<<st.back().first<<" "<<st.back().second<<" "<<dp[st.back().first][st.back().second]<<endl;
			vt.pb({st.back(), dp[st.back().first][st.back().second]});
			chk[st.back().first][st.back().second] = false;
			dp[st.back().first][st.back().second] = 0;
			st.pop_back();
		}
		dfs(x+1);
		while(!vt.empty())	vt.pop_back();
		while(v.size()>sz)	v.pop_back();
	}
}

string str;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		cin>>str;
		for(int j=0; j<N; j++){
			c[i][j] = str[j]-'0';
			if(j!=i){
				if(c[i][j]==0){
					gp[0][i].pb(j);
				}else{
					gp[1][i].pb(j);
				}
			}
			//cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
		}
	}
	for(int i=0; i<N; i++){
		vt.pb({{i, (1<<i)}, 1});
	}
	dfs(1);
	return 0;
}