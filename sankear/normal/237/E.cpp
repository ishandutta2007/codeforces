#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <cassert>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const ll inf = ll(1e15);
const int cinf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

bool used[3030];
char s[3030];
int num[3030], num2[3030], a[3030], cnt[3030], cnt2[3030][30];
int go[3030][30];
ll d[3030], pd[3030];
int p[3030];
int c[3030][3030], f[3030][3030], w[3030][3030];
vi v[3030];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("operators.in", "r", stdin);
	//freopen("operators.out", "w", stdout);
	//cerr << (sizeof(cnt2) + sizeof(go) + sizeof(c) + sizeof(f) + sizeof(w)) / 1024 / 1024 << endl;
	int n;
	scanf("%s %d", s, &n);
	int m = strlen(s);
	for(int i = 0; i < m; i++){
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < n; i++){
		scanf("%s %d", s, &a[i]);
		m = strlen(s);
		for(int j = 0; j < m; j++){
			cnt2[i][s[j] - 'a']++;
		}
	}
	int sz = 0;
	for(int i = 0; i < 26; i++){
		num[i] = sz++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			go[i][j] = sz++;
		}
		num2[i] = sz++;
	}
	int s = sz++, t = sz++;
	for(int i = 0; i < 26; i++){
		c[s][num[i]] = cnt[i];
		v[s].pb(num[i]);
		v[num[i]].pb(s);
		for(int j = 0; j < n; j++){
			c[num[i]][go[j][i]] = cinf;
			v[num[i]].pb(go[j][i]);
			v[go[j][i]].pb(num[i]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			c[go[i][j]][num2[i]] = cnt2[i][j];
			v[go[i][j]].pb(num2[i]);
			v[num2[i]].pb(go[i][j]);
		}
		c[num2[i]][t] = a[i];
		v[num2[i]].pb(t);
		v[t].pb(num2[i]);
		w[num2[i]][t] = i + 1;
		w[t][num2[i]] = -i - 1;
	}
	int flow = 0;
	while(true){
		for(int i = 0; i <= t; i++){
			d[i] = inf;
			used[i] = false;
		}
		d[s] = 0;
		for(int i = 0; i <= t; i++){
			int cur = -1;
			for(int j = 0; j <= t; j++){
				if(!used[j] && (cur == -1 || d[j] < d[cur])){
					cur = j;
				}
			}
			if(d[cur] == inf){
				break;
			}
			used[cur] = true;
			for(int j = 0; j < sz(v[cur]); j++){
				if(c[cur][v[cur][j]] - f[cur][v[cur][j]] > 0 && d[cur] + pd[cur] + w[cur][v[cur][j]] - pd[v[cur][j]] < d[v[cur][j]]){
					d[v[cur][j]] = d[cur] + pd[cur] + w[cur][v[cur][j]] - pd[v[cur][j]];
					p[v[cur][j]] = cur;
				}
			}
		}
		if(d[t] == inf){
			break;
		}
		flow++;
		int i = t;
		while(i != s){
			f[p[i]][i]++;
			f[i][p[i]]--;
			i = p[i];
		}
		for(int i = 0; i <= t; i++){
			pd[i] = min(pd[i] + d[i], inf);
		}
	}
	int sum = 0;
	for(int i = 0; i < 26; i++){
		sum += cnt[i];
	}
	if(flow != sum){
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += f[num2[i]][t] * w[num2[i]][t];
	}
	printf("%d\n", ans);
	return 0;
}