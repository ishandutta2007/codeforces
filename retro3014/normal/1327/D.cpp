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

int T, N;
int to[MAX_N+1], c[MAX_N+1];
bool vst[MAX_N+1];
vector<int> v;
bool b[MAX_N+1];

bool chk(int x){
	for(int j=v.size()-1; j>=0; j--){
		if(j+x>v.size()-1)	b[j] = true;
		else{
			if(b[j+x] && c[v[j]]==c[v[j+x]]){
				b[j] = true;
			}else{
				b[j] = false;
			}
		}
	}
	for(int j=0; j<x; j++){
		if(b[j])	return true;
	}
	return false;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		int ans = N;
		for(int i=1; i<=N; i++){
			scanf("%d", &to[i]);
			vst[i] = false;
		}
		for(int i=1; i<=N; i++){
			scanf("%d", &c[i]);
		}
		for(int i=1; i<=N; i++){
			if(!vst[i]){
				int n = i;
				while(!v.empty())	v.pop_back();
				while(1){
					v.pb(n);
					//cout<<n<<" ";
					vst[n] = true;
					n = to[n];
					if(n==i)	break;
				}//cout<<endl;
				int M = (int)v.size();
				ans = min(ans, M);
				for(int l=1; l*l<=M; l++){
					if(M%l==0){
						if(chk(l)){
							ans = min(ans, l);
						}
						if(l*l!=M){
							if(chk(M/l)){
								ans = min(ans, M/l);
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}