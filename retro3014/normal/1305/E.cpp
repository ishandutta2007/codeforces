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
const int INF = 5e8+10;
const ll INFLL = 1e18;
const int MAX_N = 5010;

int N, M;
vector<int> v;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		int x = (i-1)/2;
		if(x<=M){
			M-=x;
			v.pb(i);
			if(M==0)	break;
		}else{
			if(M==0)	break;
			v.pb(v.back() + v[v.size()-M*2]);
			M = 0;
			break;
		}
	}
	while(v.size()<N){
		v.pb(INF+v.size()*MAX_N);
	}
	if(M==0){
		for(int i=0; i<N; i++){
			printf("%d ", v[i]);
		}
	}else{
		printf("-1");
	}
	return 0;
}