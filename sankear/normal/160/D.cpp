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

using namespace std;

#define prev _prev
#define rank _rank
#define pb push_back

struct tp{
	int a, b, c, num;
};

int cur;
bool used[100100], good[100100];
int prev[100100], tin[100100], tout[100100], a[100100], b[100100], rank[100100], ans[100100];
tp p[100100];

bool operator < (const tp &a, const tp &b){
	return a.c < b.c;
}

int get(int a){
	if(prev[a] != a){
		prev[a] = get(prev[a]);
	}
	return prev[a];
}

inline void merge(int a, int b){
	if(rank[a] == rank[b]){
		prev[b] = a;
		rank[a]++;
		return;
	}
	if(rank[a] < rank[b]){
		prev[a] = b;
		return;
	}
	prev[b] = a;
}

void dfs(int a, int b, vector < vector <int> > &go, vector < vector <int> > &num){
	used[a] = true;
	tin[a] = tout[a] = ++cur;
	for(int i = 0; i < (int)go[a].size(); i++){
		if(num[a][i] == b){
			continue;
		}
		if(!used[go[a][i]]){
			dfs(go[a][i], num[a][i], go, num);
			tout[a] = min(tout[a], tout[go[a][i]]);
			if(tout[go[a][i]] > tin[a]){
				good[num[a][i]] = true;
			}
		}
		else{
			tout[a] = min(tout[a], tin[go[a][i]]);
		}
	}
}

inline void solve(int l, int r){
	vector <int> v;
	for(int i = l; i <= r; i++){
		a[i] = get(p[i].a);
		b[i] = get(p[i].b);
		if(a[i] == b[i]){
			ans[p[i].num] = 3;
			continue;
		}
		ans[p[i].num] = 2;
		v.pb(a[i]);
		v.pb(b[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	vector < vector <int> > go;
	vector < vector <int> > num;
	go.resize(v.size());
	num.resize(v.size());
	for(int i = l; i <= r; i++){
		if(a[i] == b[i]){
			continue;
		}
		int num1 = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		int num2 = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
		go[num1].pb(num2);
		num[num1].pb(i);
		go[num2].pb(num1);
		num[num2].pb(i);
	}
	for(int i = 0; i < (int)v.size(); i++){
		used[i] = false;
	}
	for(int i = 0; i < (int)v.size(); i++){
		if(!used[i]){
			dfs(i, -1, go, num);
		}
	}
	for(int i = l; i <= r; i++){
		if(a[i] != b[i] && good[i]){
			ans[p[i].num] = 1;
		}
	}
	for(int i = l; i <= r; i++){
		int num1 = get(p[i].a), num2 = get(p[i].b);
		if(num1 != num2){
			merge(num1, num2);
		}
	}
}

int main(){
	//freopen("contest.in", "r", stdin);
	//freopen("contest.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
		p[i].a--;
		p[i].b--;
		p[i].num = i;
	}
	sort(p, p + m);
	for(int i = 0; i < n; i++){
		prev[i] = i;
		rank[i] = 1;
	}
	int i = 0;
	while(i < m){
		int j = i;
		while(j + 1 < m && p[i].c == p[j + 1].c){
			j++;
		}
		solve(i, j);
		i = j + 1;
	}
	for(int i = 0; i < m; i++){
		if(ans[i] == 1){
			printf("any\n");
			continue;
		}
		if(ans[i] == 2){
			printf("at least one\n");
			continue;
		}
		printf("none\n");
	}
	return 0;
}