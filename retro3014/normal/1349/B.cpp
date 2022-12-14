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
vector<int> v, vt;
int N, K;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		bool tf = false;
		while(!v.empty())	v.pop_back();
		while(!vt.empty())	vt.pop_back();
		int n = 0;
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x);
			if(x<K)	{
				v.pb(1);
				vt.pb(-1);
			}
			else if(x==K)	{
				v.pb(2);
				vt.pb(1);
				n++;
			}
			else	{
				v.pb(3);
				vt.pb(1);
			}
		}
		if(N==1 && v[0]==2)	tf = true;
		int mx = 0;
		for(int i=N-1; i>=0; i--){
			mx+=vt[i];
			if(i!=N-1){
				if(mx>0){
					tf = true;
				}
			}
			mx = max(mx, vt[i]);
		}
		mx = 0;
		for(int i=0; i<N; i++){
			mx+=vt[i];
			if(i!=0){
				if(mx>0)	tf = true;
			}
			mx = max(mx, vt[i]);
		}
		if(n==0)	tf = false;
		if(tf){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}