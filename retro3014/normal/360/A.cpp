#include <bits/stdc++.h>

#define pb push_back
#define all(v) ((v).begin(), (v).end())
#define sortv(v) sort(all(v))
#define sz(v) ((int)(v).size())
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define umax(a, b) (a)=max((a), (b))
#define umin(a, b) (a)=min((a), (b))
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rep(i,n) FOR(i,1,n)
#define rep0(i,n) FOR(i,0,(int)(n)-1)
#define FI first
#define SE second
#define INF 1000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 5000;

int N, M;
int arr[MAX_N+1];
struct Q{
	Q(int t, int x, int y, int d) : t(t), x(x), y(y), d(d) {}
	int t;
	int x, y;
	int d;
};
vector<Q> query;
vector<int> ans;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=M; i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		query.pb({a, b, c, d});
	}
	for(int i=1; i<=N; i++){
		arr[i] = INF;
	}
	for(int i=M-1; i>=0; i--){
		Q now = query[i];
		if(now.t==1){
			for(int i=now.x; i<=now.y; i++){
				arr[i] -= now.d;
			}
		}else{
			for(int i=now.x; i<=now.y; i++){
				arr[i] = min(arr[i], now.d);
			}
		}
	}
	for(int i=1; i<=N; i++){
		arr[i] = min(arr[i], INF);
		ans.pb(arr[i]);
		if(arr[i] < -INF){
			printf("NO");
			return 0;
		}
	}
	for(int i=0; i<M; i++){
		Q now = query[i];
		if(now.t==1){
			for(int i=now.x; i<=now.y; i++){
				arr[i]+=now.d;
			}
		}else{
			int mx = arr[now.x];
			for(int i=now.x+1; i<=now.y; i++){
				mx = max(mx, arr[i]);
			}
			if(mx!=now.d){
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=0; i<N; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}