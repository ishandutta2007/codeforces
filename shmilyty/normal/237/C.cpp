
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
 
#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1E-9)
#define INF ((int)1E9)
#define sqr(x) ((x) * (x))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
  
const int maxn = (int)1e6 + 1;
bool used[maxn];
 
 
int k;
bool solve(int l, int r, int len) {
	r++;
	

	int cnt = 0;
	for (int i = l; i < r; i++) {
		cnt += !used[i];
		if (i - l >= len)
			cnt -= !used[i - len];

		if (i - l >= len - 1 && cnt < k)
			return 0;
	}

	return 1;
}
 
int main() {     

	
	memset(used, 0, sizeof(used));
	used[0] = used[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (used[i])
			continue;
		for (ll j = (ll)i * i; j < maxn; j += i)
			used[j] = 1;
	}
	
	int a, b;
	while (scanf("%d%d%d", &a, &b, &k) >= 1) {
		int l = 0, r = b - a + 2;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (solve(a, b, m))
				r = m;
			else
				l = m;
		}
		if (r == b - a + 2)
			printf("-1\n");
		else
			printf("%d\n", r);

	}	
	return 0;
}