#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include<immintrin.h>
#define ADD _mm256_add_epi32
#define OR  _mm256_or_si256
#define AND _mm256_and_si256
#define SUB _mm256_sub_epi32
#define GT _mm256_cmpgt_epi32
typedef __m256i LL;

const int maxn = 100008;
const int inf = 1e9;
using std::cin;
using std::cout;
int n, w, q;
int a[maxn], ask[maxn], min[maxn], max[maxn], ans[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> w >> q;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
	}
	for(int i = 0;i < q;++i) {
		cin >> ask[i], ask[i] = w - ask[i];;
		min[i] = max[i] = a[0];
	}
	const int Q = (q - 1 | 7) + 1 >> 3;
	for(int i = 0;i < n;++i) {
		const int v = a[i];
		LL vv = _mm256_set_epi32(v, v, v, v, v, v, v, v);
		LL * MIN = (LL*) min;
		LL * MAX = (LL*) max;
		LL * ANS = (LL*) ans;
		LL * ASK = (LL*) ask;
		for(int i = 0;i < Q;++i) {
			MIN[i] = _mm256_min_epi32(MIN[i], vv);
			MAX[i] = _mm256_max_epi32(MAX[i], vv);
			LL yes = GT(MAX[i], ADD(MIN[i], ASK[i]));
			ANS[i] = ADD(ANS[i], yes);
			MAX[i] = ADD(MAX[i], AND(SUB(vv, MAX[i]), yes));
			MIN[i] = ADD(MIN[i], AND(SUB(vv, MIN[i]), yes));
		}
	}
	for(int i = 0;i < q;++i) {
		cout << - ans[i] << '\n';
	}
}