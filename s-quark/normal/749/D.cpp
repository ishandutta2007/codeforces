#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;

//int a[MAXN], b[MAXN];
int last[MAXN];
int a[MAXN];
bool mis[MAXN];
int x[MAXN];
vector<int> s[MAXN];

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	int i, j, k;

	memset(last, -1, sizeof last);
	last[0] = 0;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		s[a].pb(b);
		last[a] = b;
	}

	for(i = 0; i <= n; i++)
		a[i] = i;
	sort(a, a+n+1, [](int i, int j){return last[i] < last[j];});

	int q;
	scanf("%d", &q);
	memset(mis, false, sizeof mis);
	while(q--){
		scanf("%d", &k);
		for(i = 0; i < k; i++){
			scanf("%d", &x[i]);
			mis[x[i]] = true;
		}

		i = n;
		while(mis[a[i]])
			i--;
		if(a[i] == 0){
			printf("0 0\n");
		}
		else{
			j = i-1;
			while(mis[a[j]])
				j--;
			int ans = *lower_bound(s[a[i]].begin(), s[a[i]].end(), last[a[j]]);
			printf("%d %d\n", a[i], ans);
		}

		for(i = 0; i < k; i++){
			mis[x[i]] = false;
		}
	}

	return 0;
}