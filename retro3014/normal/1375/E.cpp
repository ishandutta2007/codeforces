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
const int MAX_N = 1000;

int N;
int arr[MAX_N+1];
vector<int> idx[MAX_N+1];

vector<pii> ans;

void swp(int x, int y){
	int k = arr[x]; arr[x] = arr[y]; arr[y] = k;

}

vector<pii> vt;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			if(arr[i]>arr[j]){
				vt.pb({arr[j], j});
			}
		}
		sort(vt.begin(), vt.end());
		while(!vt.empty()){
			ans.pb({i, vt.back().second});
			vt.pop_back();
		}
	}
	for(pii p : ans){
		swp(p.first, p.second);
	}
	for(int i=1; i<N; i++){
		if(arr[i]>arr[i+1]){
			printf("-1");
			return 0;
		}
	}
	printf("%d\n", (int)ans.size());
	for(pii p : ans){
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}