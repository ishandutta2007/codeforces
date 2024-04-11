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
#define INF 2000000000
#define INFLL 1000000000000000000LL


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;
vector<pii> ans;

int main(){
	scanf("%lld%lld", &N, &K);
	int i = 0, j = 1;
	while(ans.size()<N){
		ans.push_back({i, j});
		i = (i+1)%K; j = (j+1)%K;
		if(i==0){
			j = (j+1)%K;
		}
		if(i==0 && j==0){
			break;
		}
	}
	if(ans.size()==N){
		printf("yes\n");
		for(int i=0; i<ans.size(); i++){
			printf("%d %d\n", ans[i].first+1, ans[i].second+1);
		}
	}else	printf("no");
	return 0;
}