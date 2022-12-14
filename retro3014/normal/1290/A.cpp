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
const int MAX_N = 3500;

int T, N, M, K;
int arr[MAX_N+1];
int mx[MAX_N+1];

priority_queue<pii, vector<pii>, greater<pii> > pq;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &M, &K);
		K = min(K, M-1);
		for(int i=1; i<=N; i++){
			scanf("%d", &arr[i]);
		}
		for(int i=1; i<=N; i++){
			int j = i+N-M;
			if(j>N)	break;
			mx[i] = max(arr[i], arr[j]);
		}
		int l = 0, r = K;
		int ans=0;
		int idx = 1;
		while(!pq.empty())	pq.pop();
		for(l=0; l<=K; l++){
			while(idx+N-M<=N-r){
				pq.push({mx[idx], idx});
				idx++;
			}
			while(!pq.empty() && pq.top().second<1+l){
				pq.pop();
			}
			ans = max(ans, pq.top().first);
			r--;
		}
		printf("%d\n", ans);
	}
	return 0;
}