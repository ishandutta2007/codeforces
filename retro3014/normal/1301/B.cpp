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

int N;
int T;

vector<int> v;
vector<int> vt;

int main(){
	scanf("%d", &T);
	while(T--){
		while(!v.empty())	v.pop_back();
		while(!vt.empty())	vt.pop_back();
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			v.pb(x);
		}
		int M = 0;
		for(int i=0; i<N-1; i++){
			if(v[i]==-1 && v[i+1]!=-1){
				vt.pb(v[i+1]);
			}
			if(v[i+1]==-1 && v[i]!=-1){
				vt.pb(v[i]);
			}
			if(v[i+1]!=-1 && v[i]!=-1){
				M = max(M, v[i+1] - v[i]);
				M = max(M, v[i]-v[i+1]);
			}
		}
		sort(vt.begin(), vt.end());
		if(vt.empty()){
			printf("0 0\n");
			continue;
		}
		//cout<<vt[0]<<" "<<vt.back()<<endl;
		int K = (vt.back() + vt[0]) / 2;
		M = max(M, max(vt.back()-K, K-vt[0]));
		printf("%d %d\n", M, K);
	}
	return 0;
}