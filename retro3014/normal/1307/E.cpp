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

const ll MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 5000;

int N, M;
int S[MAX_N+1];
vector<int> vt[MAX_N+1];
vector<int> L, R;
int F[MAX_N+1], H[MAX_N+1];
int cntL[MAX_N+1], cntR[MAX_N+1];

ll ans1, ans2;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		scanf("%d", &S[i]);
		L.pb(S[i]);
		cntL[S[i]]++;
	}
	for(int i=1; i<=M; i++){
		scanf("%d%d", &F[i], &H[i]);
		vt[F[i]].pb(H[i]);
	}
	for(int i=1; i<=N; i++){
		sort(vt[i].begin(), vt[i].end());
	}
	while(1){
		bool tf = true;
		int cnt = 0;
		ll num = 1LL;
		for(int j=1; j<=N; j++){
			if(!L.empty() && j==L.back()){
				if(vt[j].empty()){
					tf = false;
					break;
				}
				int idx = (cntL[j]<vt[j][0]) ? -1 : (int)(lower_bound(vt[j].begin(), vt[j].end(), cntL[j]) - vt[j].begin());
				if(idx==-1 || vt[j][idx]!=cntL[j]){
					tf = false;
					break;
				}
				if(vt[j].size()>=2 && ((idx!=0 && vt[j][0]<=cntR[j]) || vt[j][1]<=cntR[j])){
					cnt+=2;
					ll t = (ll)(upper_bound(vt[j].begin(), vt[j].end(), cntR[j]) - vt[j].begin());
					if(cntR[j]>=cntL[j]){
						t--;
					}
					num = (num * t) % MOD;
				}else{
					cnt+=1LL;
				}
			}
			else if(vt[j].size()>=2 && ((vt[j][0]<=cntL[j] && vt[j][1]<=cntR[j]) || (vt[j][0]<=cntR[j] && vt[j][1]<=cntL[j]))){
				cnt+=2;
				ll c1, c2, t;
				c1 = (ll)(upper_bound(vt[j].begin(), vt[j].end(), cntL[j]) - vt[j].begin());
				c2 = (ll)(upper_bound(vt[j].begin(), vt[j].end(), cntR[j]) - vt[j].begin());
				t = c1 * c2 - min(c1, c2);
				num = (num * t) % MOD;
			}else if(vt[j].size()>=1 && (vt[j][0]<=cntL[j] || vt[j][0]<=cntR[j])){
				cnt+=1;
				ll t = 0LL;
				if(vt[j][0]<=cntL[j]){
					t += (ll)(upper_bound(vt[j].begin(), vt[j].end(), cntL[j]) - vt[j].begin());
				}
				if(vt[j][0]<=cntR[j]){
					t += (ll)(upper_bound(vt[j].begin(), vt[j].end(), cntR[j]) - vt[j].begin());
				}
				//cout<<t<<endl;
				num = (num * t) % MOD;
			}
		}
		//cout<<tf<<" "<<cnt<<" "<<num<<endl;
		if(tf){
			if(cnt>ans1){
				ans1 = (ll)cnt;
				ans2 = num;
			}else if(cnt==ans1){
				ans2 = (ans2 + num) % MOD;
			}
		}
		if(L.empty())	break;
		cntL[L.back()]--;
		cntR[L.back()]++;
		R.pb(L.back());
		L.pop_back();
	}
	printf("%lld %lld", ans1, ans2);

	return 0;
}