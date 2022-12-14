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
const int MAX_N = 50;

int T;
int N, M;
string str[MAX_N+1];
vector<pii> vt;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool vst[MAX_N+1][MAX_N+1];

bool chk(int x, int y){
	return (x>=0 && y>=0 && x<N && y<M);
}

void dfs(int x, int y){
	if(vst[x][y])	return;
	if(str[x][y]=='#')	return;
	vst[x][y] = true;
	for(int i=0; i<4; i++){
		if(chk(x+dx[i], y+dy[i])){
			dfs(x+dx[i], y+dy[i]);
		}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		bool ans = true;
		scanf("%d%d", &N, &M);
		for(int i=0 ;i<N; i++){
			cin>>str[i];
			for(int j=0; j<M; j++){
				vst[i][j] = false;
				if(str[i][j]=='B')	vt.pb({i, j});
			}
		}
		while(!vt.empty()){
			int i = vt.back().first, j = vt.back().second; vt.pop_back();
			str[i][j]='#';
			for(int k=0; k<4; k++){
				if(chk(i+dx[k], j+dy[k])){
					if(str[i+dx[k]][j+dy[k]]=='G'){
						ans = false;
					}
					str[i+dx[k]][j+dy[k]] = '#';
				}
			}
		}
		dfs(N-1, M-1);
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(str[i][j]=='G'){
					if(!vst[i][j])	ans = false;
				}
			}
		}
		if(ans){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}