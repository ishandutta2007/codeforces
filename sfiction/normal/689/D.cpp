#include <cstdio>
#include <cstring>
#include <functional>

using namespace std;

const int MAXN = 2E5 + 10, MAXD = 18;

template<typename T, typename compare>
struct ST{
	int n;
	T f[MAXD][MAXN];
	compare cmp;

	void build(T a[], int n){
		ST::n = n;
		memcpy(f[0], a, n * sizeof(T));

		for (int l0 = 1, l1 = 2, i = 1; l1 < n; ++i, l0 = l1, l1 <<= 1){
			for (int j = n - l1; j >= 0; --j)
				f[i][j] = cmp(f[i - 1][j], f[i - 1][j + l0]) ? f[i - 1][j] : f[i - 1][j + l0];
		}
	}

	T query(int l, int r) const{
		if (r - l <= 1)
			return f[0][l];
		int t = 31 - __builtin_clz(r - l - 1), l0 = 1 << t;
		return cmp(f[t][l], f[t][r - l0]) ? f[t][l] : f[t][r - l0];
	}
};

ST<int, greater<int> > A;
ST<int, less<int> > B;
int a[MAXN], b[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	A.build(a, n);
	B.build(b, n);

	long long ans = 0;
	for (int i = 0; i < n; ++i){
		int low = i, high = n, mid;
		while (low < high){
			mid = low + high >> 1;
			if (A.query(i, mid + 1) < B.query(i, mid + 1))
				low = mid + 1;
			else
				high = mid;
		}
		ans -= low;
		high = n;
		while (low < high){
			mid = low + high >> 1;
			if (A.query(i, mid + 1) <= B.query(i, mid + 1))
				low = mid + 1;
			else
				high = mid;
		}
		ans += low;
	}
	printf("%I64d\n", ans);
	return 0;
}