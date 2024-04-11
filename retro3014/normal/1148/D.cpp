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

const int MAX_N = 300000;

int N;
vector<pair<pii, int> > v1, v2;
int dp[MAX_N+1];
int from[MAX_N+1];


struct SEG{
	SEG(int l, int r, int mx) : l(l), r(r), mx(mx) {}
	int l, r;
	int mx;
};

vector<SEG> seg;
void init(int idx, int s, int e){
	if(s==e)	return;
	seg[idx].l = seg.size(); seg.pb({-1, -1, 0});
	seg[idx].r = seg.size(); seg.pb({-1, -1, 0});
	init(seg[idx].l, s, (s+e)/2);
	init(seg[idx].r, (s+e)/2+1, e);
}

void update(int idx, int s, int e, int x, int y){
	if(dp[y]>=dp[seg[idx].mx]){
		seg[idx].mx = y;
	}
	if(s==e)	return;
	if(x<=(s+e)/2){
		update(seg[idx].l, s, (s+e)/2, x, y);
	}else{
		update(seg[idx].r, (s+e)/2+1, e, x, y);
	}
}

int calc(int idx, int s, int e, int x, int y){
	if(x<=s && e<=y)	return seg[idx].mx;
	if(x>e || y<s)	return 0;
	int i1 = calc(seg[idx].l, s, (s+e)/2, x, y), i2 = calc(seg[idx].r, (s+e)/2+1, e, x, y);
	return (dp[i1]>dp[i2])?i1:i2;
}


int main(){
	scanf("%d", &N);
	seg.pb({-1, -1, 0});
	init(0, 1, N*2);
	for(int i=1; i<=N; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x>y){
			v1.pb({{y, x}, i});
		}else{
			v2.pb({{y, x}, i});
		}
	}
	if(v1.size()>v2.size()){
		sort(v1.begin(), v1.end());
		printf("%d\n", v1.size());
		for(int i=0; i<v1.size(); i++){
			printf("%d ", v1[i].second);
		}
	}else{
		sort(v2.begin(), v2.end());
		printf("%d\n", v2.size());
		while(!v2.empty()){
			printf("%d ", v2.back().second);
			v2.pop_back();
		}
	}
	return 0;
}