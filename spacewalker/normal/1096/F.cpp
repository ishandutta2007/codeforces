#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e % 2 == 1 ? b : 1) * modexp(b*b%MOD, e/2) % MOD;
}

ll modinv(ll x) {
	return modexp(x, MOD - 2);
}

/*
so first let's consider the inversions among the inserted pairs.
we know that E[i appears before j] = 1/2.
so E[inv] = n*(n-1)/4

now that we have that, let's do inv among non-ins pairs
this is trivial, sweep and do fenwick

now the hard part: inv among ins and non-ins
part 1
*/

struct modFrac {
	ll p, q;
	modFrac(ll p, ll q) : p(p % MOD), q(q % MOD) {}
	ll getModValue() {return p * modinv(q)  % MOD;}
	const modFrac operator + (const modFrac &other) {
		return modFrac((p*other.q % MOD + q*other.p % MOD) % MOD, q*other.q);
	}
	const modFrac operator * (const modFrac &other) {
		return modFrac(p*other.p % MOD, q*other.q & MOD);
	}
};

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int n) : n(n), tree(n+1) {}
	int LSB(int i) {return (i&(-i));}
	void add(int i, int v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;
	}
	int prefixSum(int i) {
		int ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
		return ans;
	}
	int suffixSum(int i) {
		return prefixSum(n-1) - prefixSum(i-1);
	}
};

int main() {
	ll n; scanf("%lld", &n);
	vector<int> arr(n);
	vector<int> placeIn(n, -1);
	vector<bool> notDeleted(n);
	ll deleteCount = n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		--arr[i];
		if (arr[i] == -2) continue;
		notDeleted[arr[i]] = true;
		placeIn[arr[i]] = i;
		--deleteCount;
	}
	// printf("HERE\n");
	vector<int> deletesBefore(n);
	vector<int> deletesAfter(n);
	deletesBefore[0] = (arr[0] == -2 ? 1 : 0);
	deletesAfter[n-1] = (arr[n-1] == -2 ? 1 : 0);
	for (int i = 1; i < n; ++i) {
		deletesBefore[i] = deletesBefore[i-1] + (arr[i] == -2 ? 1 : 0);
	}
	for (int i = n - 2; i >= 0; --i) {
		deletesAfter[i] = deletesAfter[i+1] + (arr[i] == -2 ? 1 : 0); 
	}
	// first: add inversions among deleted elems
	modFrac ans(deleteCount*(deleteCount-1), 4);
	// then: add inversions among non-deleted elems
	fenwick isCounted(n);
	for (int i = 0; i < n; ++i) {
		if (arr[i] != -2) {
			ans = (ans + modFrac(isCounted.suffixSum(arr[i]), 1));
			isCounted.add(arr[i], 1);
		}
	}
	// next: add inversions of the form [...(del)...(nondel)]
	// so the del is larger
	ll weightedByDel = 0;
	for (int i = 0; i < n; ++i) {
		if (notDeleted[i]) {
			weightedByDel += deletesBefore[placeIn[i]];
		} else {
			ans = ans + modFrac(weightedByDel, deleteCount);
			// printf("%lld ahead inv from %d\n", weightedByDel, i);
		}
	}
	// last: add inversions of the form [...(nondel)...(del)]
	// so the del is smaller
	weightedByDel = 0;
	for (int i = n-1; i >= 0; --i) {
		if (notDeleted[i]) weightedByDel += deletesAfter[placeIn[i]];
		else {
			ans = ans + modFrac(weightedByDel, deleteCount);
			// printf("%lld behind inv from %d\n", weightedByDel, i);
		}
	}
	printf("%lld\n", ans.getModValue());
	return 0;
}