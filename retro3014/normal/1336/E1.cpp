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

const ll MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1;
const int MAX_M = 35;
const int MAX_K = 12;
int N;
int M;

vector<ll> vt;
vector<ll> vt2;
vector<ll> vt3;

ll now;
ll cnt[MAX_M+1][(1<<MAX_K)];

ll ans[MAX_M*2+1];

void dfs(int x){
	if(x==(int)vt3.size()){
		int num = 0;
		int t = (int)(now/(1LL<<(ll)MAX_K));
		num = __builtin_popcount(t);
		cnt[num][now%(1<<MAX_K)] = (cnt[num][now%(1<<MAX_K)] + 1LL) % MOD;
		return;
	}
	dfs(x+1);
	now = (now ^ vt3[x]);
	dfs(x+1);
	now = (now ^ vt3[x]);
}

ll cnt2[MAX_M+1][(1<<MAX_K)];

void dfs2(int x){
	if(x==(int)vt2.size()){
		for(int i=0; i<(1<<MAX_K); i++){
			int t = ((int)now ^ i);
			int num = __builtin_popcount(t);
			cnt2[num][i]= (cnt2[num][i]+1)%MOD;
		}
		return;
	}
	dfs2(x+1);
	now = (now ^ vt2[x]);
	dfs2(x+1);
	now = (now ^ vt2[x]);
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		ll x; scanf("%lld", &x);
		vt.pb(x);
	}
	ll two = (1LL<<(ll)(M-1));
	while(two>0){
		ll n = -1;
		for(int i=0; i<vt.size(); i++){
			if((vt[i]&two)!=0){
				vt2.pb(vt[i]);
				n = vt[i];
				vt[i] = vt.back(); vt.pop_back();
				break;
			}
		}
		if(n!=-1){
			for(int i=0; i<vt.size(); i++){
				if((vt[i] & two)!=0){
					vt[i] = (vt[i] ^ n);
				}
			}
		}
		two/=2LL;
	}
	ll tt = 1LL;
	while(!vt.empty()){
		vt.pop_back();
		tt=(tt*2LL)%MOD;
	}
	//cout<<tt<<endl;
	for(int i=0; i<vt2.size(); ){
		if(vt2[i]>=(1<<MAX_K)){
			vt3.pb(vt2[i]);
			vt2[i] = vt2.back();
			vt2.pop_back();
		}else{
			i++;
		}
	}
	//cout<<tt<<endl;
	dfs(0);
	//cout<<tt<<endl;
	now = 0;
	dfs2(0);
	//cout<<tt<<endl;
	for(int i=0 ;i<(1<<MAX_K); i++){
		for(int j=0; j<=MAX_M; j++){
			for(int k=0; k<=MAX_M; k++){
				if(j+k>M)	break;
				ll add = (cnt[j][i] * cnt2[k][i]) % MOD;
				ans[j+k] = (ans[j+k] + add) % MOD;
			}
		}
	}
	for(int i=0; i<=M; i++){
		ans[i] = (ans[i] * tt) %MOD;
		printf("%lld ", ans[i]);
	}
	return 0;
}