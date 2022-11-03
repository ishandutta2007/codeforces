#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E6 + 10;
const ll INF = 1ll << 60;

int n, A, B;
int a[MAXN], b[MAXN];
ll f[MAXN][3];
ll ans;

void getPrime(int x, vector<int> &lst){
	int i = 2;
	for (; i * i <= x; ++i)
		if (x % i == 0){
			lst.push_back(i);
			for (; x % i == 0; x /= i);
		}
	if (x > 1)
		lst.push_back(x);
}

void getDP(int a[], int t){
	if (a[1] % t == 0)
		f[1][0] = 0;
	else if ((a[1] - 1) % t == 0 || (a[1] + 1) % t == 0)
		f[1][0] = B;
	else
		return;
	for (int i = 2; i <= n; ++i){
		if (a[i] % t == 0){
			f[i][0] = f[i - 1][0];
			f[i][2] = min(f[i - 1][1], f[i - 1][2]);
		}
		else if ((a[i] - 1) % t == 0 || (a[i] + 1) % t == 0){
			f[i][0] = f[i - 1][0] + B;
			f[i][2] = min(f[i - 1][1], f[i - 1][2]) + B;
		}
		else{
			f[i][0] = f[i][2] = INF;
		}
		f[i][1] = min(f[i - 1][0], f[i - 1][1]) + A;
	}
	ans = min(ans, min(f[n][0], min(f[n][1], f[n][2])));
}

int main(){
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), b[n - i + 1] = a[i];
	vector<int> lst;
	getPrime(a[1] - 1, lst);
	getPrime(a[1], lst);
	getPrime(a[1] + 1, lst);
	getPrime(a[n] - 1, lst);
	getPrime(a[n], lst);
	getPrime(a[n] + 1, lst);
	sort(lst.begin(), lst.end());
	lst.erase(unique(lst.begin(), lst.end()), lst.end());

	ans = INF;
	f[1][1] = f[1][2] = INF;
	for (int k = 0; k < lst.size(); ++k){
		getDP(a, lst[k]);
		getDP(b, lst[k]);
	}
	printf("%I64d\n", ans);
	return 0;
}