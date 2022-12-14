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
const int INF = 1e6;
const ll INFLL = 1e18;
const int MAX_N = 100000;

int N;
int arr[MAX_N+1];
int ans[MAX_N+1];
vector<int> vt;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		if(arr[i]!=arr[i-1]){
			ans[i] = arr[i-1];
			int x = arr[i-1]+1;
			while(x<arr[i]){
				if(vt.empty()){
					printf("-1");
					return 0;
				}
				ans[vt.back()] = x;
				x++; vt.pop_back();
			}
		}else{
			vt.pb(i);
		}
	}
	while(!vt.empty()){
		ans[vt.back()] = INF;
		vt.pop_back();
	}
	for(int i=1; i<=N; i++)	printf("%d ", ans[i]);
	return 0;
}