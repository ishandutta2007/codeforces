#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;
const ll MOD = 1E9 + 7;

int n;
char s[MAXN];
vector<int> lst[MAXN];

ll inv[MAXN], com[MAXN], cominv[MAXN];
ll exp25[MAXN];

void getInv(){
	inv[0] = 0, inv[1] = 1;
	com[0] = com[1] = 1;
	cominv[0] = cominv[1] = 1;
	exp25[0] = 1, exp25[1] = 25;
	for (int i = 2; i < MAXN; ++i){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		com[i] = com[i - 1] * i % MOD;
		cominv[i] = cominv[i - 1] * inv[i] % MOD;
		exp25[i] = exp25[i - 1] * 25 % MOD;
	}
}

ll binom(int m, int n){
	return com[m] * cominv[n] % MOD * cominv[m - n] % MOD;
}

void build(char s[]){
	n = strlen(s);
	if (lst[n].size())
		return;
	lst[n].resize(MAXN);
	lst[n][n] = 1;
	for (int i = n + 1; i < MAXN; ++i)
		lst[n][i] = (lst[n][i - 1] * 26ll + exp25[i - n] * binom(i - 1, n - 1)) % MOD;
}

int main(){
	getInv();

	int m;
	scanf("%d", &m);
	scanf("%s", s);
	build(s);
	int com, t;
	for (int i = 0; i < m; ++i){
		scanf("%d", &com);
		if (com == 1){
			scanf("%s", s);
			build(s);
		}
		else{
			scanf("%d", &t);
			printf("%d\n", t < n ? 0 : lst[n][t]);
		}
	}
	return 0;
}