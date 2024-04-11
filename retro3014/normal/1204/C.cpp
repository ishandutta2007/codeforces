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
const int MAX_N = 100;

int N, M;
int d[MAX_N+1][MAX_N+1];
string str;
vector<int> v;
int dist[MAX_N+1][MAX_N+1];

deque<int> dq;

void bfs(int x){
	dq.pb(x);
	while(!dq.empty()){
		int now = dq.front(); dq.pop_front();
		for(int i = 1; i <= N; i++){
			if(i==now)	continue;
			if(dist[x][i]!=INF)	continue;
			if(d[now][i]==0)	continue;
			dist[x][i] = dist[x][now]+1;
			dq.pb(i);
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		cin>>str;
		for(int j=1; j<=N; j++){
			d[i][j] = (int)(str[j-1]-'0');
			//cout<<d[i][j];
		}
		//cout<<endl;
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
		bfs(i);
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int x; scanf("%d", &x);
		if(v.size()>=2 && dist[v[v.size()-2]][x]==(dist[v[v.size()-2]][v.back()] + dist[v.back()][x])){
			v.pop_back();
		}
		v.push_back(x);
	}
	printf("%d\n", v.size());
	for(int i=0; i<v.size(); i++){
		printf("%d ", v[i]);
	}
	return 0;
}