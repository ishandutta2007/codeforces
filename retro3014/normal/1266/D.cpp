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
const int MAX_N = 100000;

int N, M;

vector<int> g1[MAX_N+1], g2[MAX_N+1];


ll d[MAX_N+1];
struct S{
	int x, y;
	ll d;
};
vector<S> v;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(x==y)	continue;
		d[y]+=z; d[x]-=z;
	}
	int idx1 = 1, idx2 = 1;
	while(idx1<=N && idx2<=N){
		if(d[idx1]<=0){
			idx1++;
		}else if(d[idx2]>=0){
			idx2++;
		}else{
			if(d[idx1]<-d[idx2]){
				d[idx2]+=d[idx1];
				v.pb({idx2, idx1, d[idx1]});
				d[idx1] = 0;
				idx1++;
			}else if(d[idx1]==d[idx2]){
				v.pb({idx2, idx1, d[idx1]});
				d[idx1] = d[idx2] = 0;
				idx1++; idx2++;
			}else{
				v.pb({idx2, idx1, -d[idx2]});
				d[idx1] += d[idx2]; d[idx2] = 0;
				idx2++;
			}
		}
	}
	printf("%d\n", v.size());
	for(int i=0; i<v.size(); i++){
		printf("%d %d %lld\n", v[i].x, v[i].y, v[i].d);
	}
	return 0;
}