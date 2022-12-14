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

int sz[MAX_N+1];
int p[MAX_N+1];

void dfs(int x){
	sz[x] = 1;
	for(int i : gp[x]){
		if(i!=p[x]){
			p[i] = x;
			dfs(i);
			sz[x]+=sz[i];
		}
	}
}

vector<pii> vt;
struct Ans{
	int x, y, z;
};
vector<Ans> ans;
int dist[MAX_N+1];

void calc(int x, int y, int z){
	ans.pb({x, p[x], y - dist[x]});
	dist[x] = y;
	y+=z;
	for(int i : gp[x]){
		if(i==p[x])	continue;
		dist[i] = dist[x];
		calc(i, y, z);
		y+=sz[i]*z;
	}
}

int main(){
	scanf("%d", &N);
	if(N==1){
		return 0;
	}
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	int cen = 1;
	while(1){
		bool tf = true;
		for(int i : gp[cen]){
			if(i==p[cen])	continue;
			if(sz[i]>N/2){
				tf = false;
				cen = i;
				break;
			}
		}
		if(tf)	break;
	}
	//cout<<cen<<endl;
	for(int i=1; i<=N; i++)	p[i] = 0;
	dfs(cen);
	for(int i : gp[cen]){
		vt.pb({sz[i], i});
	}
	sort(vt.begin(), vt.end());
	int sum = 0, idx = 0;
	while(1){
		calc(vt[idx].second, sum+1, 1);
		sum+=sz[vt[idx].second];
		idx++;
		if(sum>N/3){
			break;
		}
	}
	int t = sum;
	while(idx<vt.size()){
		calc(vt[idx].second, t, sum);
		t += sum * sz[vt[idx].second];
		idx++;
	}
	for(int i=0; i<ans.size(); i++){
		printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
	}
	return 0;
}