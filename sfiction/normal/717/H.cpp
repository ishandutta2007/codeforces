#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int TAT;

vector<int> E[MAXN], U[MAXN];
int g[MAXN], f[MAXN], ans[MAXN];
PII Q[MAXN];

void read(){
	TAT = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		U[x].push_back(y);
		U[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		E[i].resize(x);
		for(int j = 0; j < x; j++){
			scanf("%d", &E[i][j]);
			f[E[i][j]] = 1;
			TAT = max(TAT, E[i][j]);
		}
	}
}

int check(){
	for(int i = 1; i <= n; i++){
		int p = 0, q = 0;
		for(int j = 0; j < E[i].size(); j++)
			if (g[E[i][j]] == 1)
				p = 1;
			else
				q = 1;
		if (p == 0 || q == 0)
			return 0;
	}
	return 1;
}

void solve(){
	do{
		for(int i = 1; i <= TAT; i++)
			g[i] = rand() % 2 + 1;
	}while(!check());
	for(int i = 1; i <= n; i++){
		Q[i] = PII(E[i].size(), i);
	}
	sort(Q + 1, Q + 1 + n);
	for(int i = n; i >= 1; i--){
		int x = Q[i].second;
		int p = 0, q = 0;
		for(int j = 0; j < U[x].size(); j++){
			int y = U[x][j];
			if (ans[y] != 0){
				if (g[ans[y]] == 1)
					p++;
				else
					q++; 
			}
		}
		if (p < q){
			for(int j = 0; j < E[x].size(); j++){
				if (g[E[x][j]] == 1){
					ans[x] = E[x][j];
					break;
				}
			}
		}
		else{
			for(int j = 0; j < E[x].size(); j++){
				if (g[E[x][j]] == 2){
					ans[x] = E[x][j];
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	for(int i = 1; i <= TAT; i++)
		printf("%d%c", g[i], " \n"[i == TAT]);
}

void printans(){

}
	

int main(){
	srand(time(NULL));
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}