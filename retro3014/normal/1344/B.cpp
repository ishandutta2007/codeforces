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

int N, M;
string str[MAX_N+1];
bool chk[MAX_N+1][MAX_N+1];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vst[MAX_N+1][MAX_N+1];


void dfs(int x, int y){
	vst[x][y] = true;
	for(int i=0; i<4; i++){
		if(x+dx[i]<0 || x+dx[i]>=N || y+dy[i]<0 || y+dy[i]>=M)	continue;
		if(vst[x+dx[i]][y+dy[i]] || !chk[x+dx[i]][y+dy[i]])	continue;
		dfs(x+dx[i], y+dy[i]);
	}
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		cin>>str[i];
		for(int j=0; j<M; j++){
			chk[i][j] = (str[i][j]=='#');
		}
	}
	bool b1 = false, b2 = false;
	for(int i=0; i<N; i++){
		bool tf = false;
		for(int j=0; j<M; j++){
			if(chk[i][j]){
				while(j<M-1 && chk[i][j+1])	j++;
				while(j<M-1){
					j++;
					if(chk[i][j]){
						printf("-1");
						return 0;
					}
				}
				tf = true;
				break;
			}
		}
		if(!tf){
			b1 = true;
		}
	}
	for(int j=0; j<M; j++){
		bool tf = false;
		for(int i=0; i<N; i++){
			if(chk[i][j]){
				while(i<N-1 && chk[i+1][j])	i++;
				while(i<N-1){
					i++;
					if(chk[i][j]){
						printf("-1");
						return 0;
					}
				}
				tf = true;
				break;
			}
		}
		if(!tf){
			b2 = true;
		}
	}
	if(b1 || b2){
		if(!(b1 && b2)){
			printf("-1");
			return 0;
		}
	}
	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(chk[i][j] && !vst[i][j]){
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}