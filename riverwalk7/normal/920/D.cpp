#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, k, x;
int a[5050];
bool dp[5050][5050];
bool u[5050][5050];

bool get(int p, int g){
	if(g == x % k) return true;
	if(p == 0) return false;
	if(u[p][g]) return dp[p][g];
	u[p][g] = 1;
	dp[p][g] = get(p-1, g);
	dp[p][g] |= get(p-1, (g+a[p]) % k);
	return dp[p][g];
}
void no(){
	cout << "NO\n";
	exit(0);
}
int used[5050];
int last = 0;
void rec(int p, int g){
	if(g == x % k) return;
	if(get(p-1, g)){
		rec(p-1, g);
	}
	else{
		last = p;
		used[p] = 1;
		rec(p-1, (g + a[p]) % k);
	}
}
void solve(){
	cin >> n >> k >> x;
	int sum = 0;
	for(int i = 1; i <=n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum < x) no();
	if(!get(n, 0)) no();
	printf("YES\n");
	rec(n, 0);
	int nused = 0;
	for(int i = 1; i <= n; i++){
		if(!used[i]) nused = i;
	}
	for(int i = 1; i <= n; i++){
		if(used[i]) {
			if(last == i) continue;
			if(a[i])printf("%d %d %d\n", (int)((a[i] + k - 1)/k), i, last);
			a[last] += a[i];
		}
		else {
			if(i == nused) continue;
			if(a[i]) printf("%d %d %d\n", (int)((a[i] + k - 1)/k), i, nused);
			a[nused] += a[i];
		}
	}
	if(nused == 0) {
		if(last == 1) nused = 2;
		else nused = 1;
	}
	if(last == 0){
		last = 1;
		if(x>0) printf("%d %d %d\n", x/k, nused, 1);
	}else if(a[last] > x){
		printf("%d %d %d\n", (int)((a[last] - x + k-1)/k), last, nused);
	}else if(a[last] < x){
		printf("%d %d %d\n", (int)((x-a[last] + k-1)/k), nused, last);
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}