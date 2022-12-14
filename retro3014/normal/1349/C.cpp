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
const ll INFLL = 2e18;
const int MAX_N = 1000;

int N, M, Q;
string str[MAX_N+1];
ll t[MAX_N+1][MAX_N+1];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool is_in(int x, int y){
	return (x>=0 && x<N && y>=0 && y<M);
}

deque<pii> dq;

int main(){
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0; i<N; i++){
		cin>>str[i];
		for(int j=0; j<M; j++){
			t[i][j] = INFLL;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			bool tf = false;
			for(int k=0; k<4; k++){
				if(is_in(i+dx[k], j+dy[k])){
					if(str[i][j]==str[i+dx[k]][j+dy[k]]){
						t[i][j] = 0LL;
						dq.pb({i, j});
					}
				}
			}
		}
	}
	while(!dq.empty()){
		int x = dq.front().first, y = dq.front().second;
		dq.pop_front();
		ll nt = t[x][y];
		for(int i=0; i<4; i++){
			if(is_in(x+dx[i], y+dy[i])){
				if(t[x+dx[i]][y+dy[i]]>nt+1LL){
					t[x+dx[i]][y+dy[i]] = nt+1LL;
					dq.pb({x+dx[i], y+dy[i]});
				}
			}
		}
	}
	for(int i=1; i<=Q; i++){
		int x, y;
		ll T;
		scanf("%d %d %lld", &x, &y, &T);
		x--; y--;
		if(T<(ll)t[x][y]){
			printf("%c\n", str[x][y]);
		}else{
			T = (T - (ll)t[x][y]);
			T+=(ll)(str[x][y]-'0');
			printf("%lld\n", T%2LL);
		}
	}
	return 0;
}