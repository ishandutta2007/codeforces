#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define pb push_back

typedef long long ll;

const int maxn = 50010;
const int maxk = 510;

ll ans;
int k;
ll d[maxn][maxk];
bool used[maxn];
ll sum[maxk];
vector <int> v[maxn];

void dfs(int a){
	used[a] = true;
	vector <int> ch;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i]]){
			dfs(v[a][i]);
			ch.pb(v[a][i]);
			for(int j = 0; j < k; j++){
				d[a][j + 1] += d[v[a][i]][j];
			}
		}
	}
	d[a][0]++;
	ans += d[a][k];
	for(int i = 1; i < k; i++){
		sum[i] = 0;
	}
	for(int i = 0; i < (int)ch.size(); i++){
		for(int j = 1; j < k; j++){
			ans += d[ch[i]][j - 1] * sum[k - j];
		}
		for(int j = 1; j < k; j++){
			sum[j] += d[ch[i]][j - 1];
		}
	}
}

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout << (sizeof(d)) / 1024 / 1024 << endl;
	int n;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	ans = 0;
	dfs(0);
	cout << ans << endl;
	return 0;
}