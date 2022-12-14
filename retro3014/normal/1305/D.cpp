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
const int MAX_N = 1000;

int N;
vector<int> gp[MAX_N+1];
int deg[MAX_N+1];

vector<int> v;

int query(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int r; scanf("%d", &r);
	return r;
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
		deg[a]++; deg[b]++;
	}
	for(int i=1; i<=N; i++)	v.pb(i);
	while(1){
		if(v.size()==1){
			printf("! %d\n", v[0]);
			fflush(stdout);
			return 0;
		}
		int n1=0, n2 = 0;
		for(int i=0; i<v.size(); i++){
			if(deg[v[i]]==1){
				if(n1==0)	n1 = v[i];
				else n2 = v[i];
			}
		}
		int x = query(n1, n2);
		if(x==n1 || x==n2){
			printf("! %d\n", x);
			fflush(stdout);
			return 0;
		}
		for(int i : gp[n1])	deg[i]--;
		for(int i : gp[n2])	deg[i]--;
		for(int i=0; i<v.size(); i++){
			if(v[i]==n1 || v[i]==n2){
				v[i] = v.back(); v.pop_back();
				i--;
			}
		}
	}
	return 0;
}