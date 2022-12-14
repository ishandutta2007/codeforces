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
const int MAX_K = 60;
const int MAX_N = 100000;

int N;
vector<int> gp2[MAX_K+1];
vector<int> gp[MAX_N+1];
bool vst[MAX_N+1];
int num[MAX_N+1];
int dist[MAX_N+1];
int from[MAX_N+1];
int ans;
deque<int> dq;

void bfs(int x){
	while(!dq.empty())	dq.pop_back();
	dq.pb(x);
	dist[x] = 0;
	vst[x] = true;
	from[x] = x;
	int num = 1;
	while(!dq.empty()){
		int sz = dq.size();
		while(sz--){
			int now = dq.front(); dq.pop_front();
			for(int i : gp[now]){
				if(i==x)	continue;
				if(!vst[i]){
					vst[i] = true;
					dist[i] = num;
					from[i] = now;
					dq.push_back(i);
				}else{
					if(from[i]==now || from[now]==i)	continue;
					ans = min(ans, dist[i] + dist[now]+1);
				}
			}
		}
		num++;
	}
}


int main(){
	scanf("%d", &N);
	ans = INF;
	for(int i=0; i<N; i++){
		ll x;
		scanf("%lld", &x);
		for(int j=0; j<MAX_K ;j++){
			if(x%(ll)2==1){
				gp2[j].pb(i);
			}
			x/=2;
		}
	}
	for(int i=0 ;i<MAX_K; i++){
		if(gp2[i].size()>=3){
			printf("3");
			return 0;
		}
		if(gp2[i].size()==2){
			gp[gp2[i][0]].pb(gp2[i][1]);
			gp[gp2[i][1]].pb(gp2[i][0]);
			//cout<<gp2[i][1]<<" "<<gp2[i][0]<<endl;
		}
	}
	for(int i=0; i<N; i++){
		if(gp[i].empty())	continue;
		for(int j=0; j<N; j++){
			vst[j] = false;
			dist[j] = 0;
			from[j] = 0;
		}
		bfs(i);
	}
	if(ans==INF){
		printf("-1\n");
	}else{
		printf("%d\n", ans);
	}
	return 0;
}