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

const int MAX_N = 50;

int N;
string str[MAX_N+1];
int dp[MAX_N+1][MAX_N+1][MAX_N+1][MAX_N+1];
bool vst[MAX_N+1][MAX_N+1][MAX_N+1][MAX_N+1];

int ans(int x1, int y1, int x2, int y2){
	if(x1>x2 || y1>y2)	return 0;
	if(vst[x1][y1][x2][y2]){
		return dp[x1][y1][x2][y2];
	}
	vst[x1][y1][x2][y2] = true;
	if(x1==x2 && y1 == y2){
		if(str[x1][y1]=='#')	{
			dp[x1][y1][x2][y2] = 1;
			return 1;
		}
		return 0;
	}
	int ret = max(x2-x1+1, y2 - y1 + 1);
	for(int i=x1; i<=x2; i++){
		bool tf = true;
		for(int j=y1; j<=y2; j++){
			if(str[i][j]=='#'){
				tf = false;
				break;
			}
		}
		if(tf){
			ret = min(ret, ans(x1, y1, i-1, y2) + ans(i+1, y1, x2, y2));
		}
	}
	for(int j=y1; j<=y2; j++){
		bool tf = true;
		for(int i=x1; i<=x2; i++){
			if(str[i][j]=='#'){
				tf = false;
				break;
			}
		}
		if(tf){
			ret = min(ret, ans(x1, y1, x2, j-1) + ans(x1, j+1, x2, y2));
		}
	}
	dp[x1][y1][x2][y2] = ret;
	return ret;
}

int main(){	
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		cin>>str[i];
	}
	printf("%d", ans(0, 0, N-1, N-1));

	return 0;
}