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
const int MAX_N = 500;

int T;
int N;
int arr[MAX_N+1];
int b[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		bool tf = false;
		for(int i=1; i<=N; i++){
			scanf("%d", &arr[i]);
			if(i!=1 && arr[i]<arr[i-1])	tf = true;
		}
		for(int i=1; i<=N; i++){
			scanf("%d", &b[i]);
			if(i!=1 && b[i]!=b[i-1]){
				tf = false;
			}
		}
		if(tf){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	return 0;
}