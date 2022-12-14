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

int N, L, R;

vector<int> v;
int ans1, ans2;

int main(){
	cin>>N>>L>>R;
	for(int i=1; i<=(1<<25); i*=2){
		v.pb(i);
	}
	for(int i=0; i<L; i++){
		ans1+=v[i];
	}
	ans1 += v[0] * (N-L);
	int sum = 0;
	for(int i=0; i<R; i++){
		sum += v[i];
		ans2 = max(ans2, sum + (v[i] * (N-i-1)));
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}