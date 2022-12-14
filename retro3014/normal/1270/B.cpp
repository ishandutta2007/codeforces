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

int T;
int N;

int main(){
	scanf("%d", &T);
	while(T--){
		bool tf = false;
		scanf("%d", &N);
		int mx=0, idx=0;
		int mx2 = 0, idx2 = 0;
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			if(tf)	continue;
			if(i==1){
				mx = -x+i;
				idx = 1;
				mx2 = x+i;
				idx2 = 1;
				continue;
			}
			if(x-i + mx >= 1){
				printf("YES\n");
				printf("%d %d\n", idx, i);
				tf = true;
			}
			if(-x-i+mx2>=1){
				printf("YES\n");
				printf("%d %d\n", idx2, i);
				tf = true;
			}
			if(mx<-x+i){
				mx = -x+i;
				idx = i;
			}
			if(mx2<x+i){
				mx2 = x+i;
				idx2 = i;
			}
		}
		if(!tf)printf("NO\n");
	}
	return 0;
}