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
const int MAX_N = 200000;

int N, Q;
int arr[MAX_N+1];
int cnt[MAX_N+1];
bool vst[MAX_N+1];

vector<int> v;
int M = 0;
int ans = 0;

int main(){
	cin>>N>>Q;
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}
	for(int i=1; i<=N; i++){
		if(vst[arr[i]]==false){
			M++;
			v.pb(cnt[arr[i]]);
			vst[arr[i]] = true;
		}
		cnt[arr[i]]--;
		if(cnt[arr[i]]==0){
			M--;
		}
		if(M==0 && !v.empty()){
			sort(v.begin(), v.end());
			for(int i=0; i<v.size()-1; i++){
				ans += v[i];
			}
			while(!v.empty())	v.pop_back();
		}
	}
	if(M==0 && !v.empty()){
			sort(v.begin(), v.end());
			for(int i=0; i<v.size()-1; i++){
				ans += v[i];
			}
			while(!v.empty())	v.pop_back();
		}
	cout<<ans;
	return 0;
}