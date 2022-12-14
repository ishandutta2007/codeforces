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
const int MAX_N = 300000;

int T, N;
int arr[MAX_N+1];
int idx[MAX_N+1];
int l[MAX_N+1], r[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%d", &arr[i]);
			idx[arr[i]] = i;
			l[i] = i-1;
			r[i] = i+1;
		}
		l[1] = r[N] = -1;
		bool tf = true;
		for(int i=1; i<=N; i++){
			int n = idx[i];
			if(l[n]==-1){
				break;
			}else if(r[n]==-1){
				tf = false;
				break;
			}
			l[r[n]] = l[n];
			r[l[n]] = r[n];
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}