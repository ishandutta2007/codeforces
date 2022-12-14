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

int T, N;
vector<pii> vt1, vt2;
int A[MAX_N+1], B[MAX_N+1];


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1; i<=N; i++)	scanf("%d", &A[i]);
		for(int i=1; i<=N; i++)	scanf("%d", &B[i]);
		while(!vt1.empty())	vt1.pop_back();
		while(!vt2.empty())	vt2.pop_back();
		for(int i=1; i<=(N+1)/2; i++){
			int x = A[i], y = A[N+1-i];
			vt1.pb({min(x, y), max(x, y)});
			x = B[i], y = B[N+1-i];
			vt2.pb({min(x, y), max(x, y)});
		}
		sort(vt1.begin(), vt1.end()); sort(vt2.begin(), vt2.end());
		bool ans = true;
		for(int i=0; i<vt1.size(); i++){
			if(vt1[i].first!=vt2[i].first || vt1[i].second!=vt2[i].second)	ans = false;
		}
		if(N%2==1){
			if(A[(N+1)/2]!=B[(N+1)/2])	ans = false;
		}
		if(ans){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}