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
const int MAX_N = 100;

int N, M;
vector<pii> vt;
vector<int> v;
string str[MAX_N+1];
bool chk[MAX_N+1];

vector<string> ans;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		cin>>str[i];
		bool tf = true;
		for(int j=0; j<M; j++){
			if(str[i][j]!=str[i][M-j-1]){
				tf = false;
				break;
			}
		}
		if(tf){
			v.pb(i);
		}
		for(int j=1; j<i; j++){
			tf = true;
			for(int k=0; k<M; k++){
				if(str[i][k]!=str[j][M-k-1]){
					tf = false;
					break;
				}
			}
			if(tf){
				vt.pb({j, i});
				break;
			}
		}
	}
	for(int i=0; i<vt.size(); i++){
		chk[vt[i].first] = chk[vt[i].second] = true;
		ans.pb(str[vt[i].first]);
	}
	for(int i=0; i<v.size(); i++){
		if(!chk[v[i]]){
			ans.pb(str[v[i]]);
			break;
		}
	}
	for(int i=vt.size()-1; i>=0; i--){
		ans.pb(str[vt[i].second]);
	}
	printf("%d\n", (int)ans.size() * M);
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}