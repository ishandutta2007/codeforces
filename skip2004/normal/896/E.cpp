#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include "immintrin.h"
#include "emmintrin.h"
#include<bits/stdc++.h>
typedef __m256i LL;
inline LL sum(LL x,LL y){ return _mm256_add_epi32(x,y); }
inline LL sub(LL x,LL y){ return _mm256_sub_epi32(x,y); }
inline LL greater(LL x,LL y){ return _mm256_cmpgt_epi32(x,y); }
inline LL eql(LL x,LL y){ return _mm256_cmpeq_epi32(x,y); }
inline LL And(LL x,LL y){ return _mm256_and_si256(x,y); }
const int maxn = 100100;
int n,m,a[maxn];
inline int query(int l,int r,int x){
	int ans = 0;
	for(;l % 8 != 0 && l <= r; ++l) ans += a[l] == x;
	for(;r % 8 != 7 && l <= r; --r) ans += a[r] == x;
	LL * p = (LL *)(a + l),s = _mm256_set1_epi32(x),ret = _mm256_set1_epi32(0);
	for(int i = r - l + 1 >> 3;i;) ret = sum(ret,eql(*p,s)),++p,--i;
	int * wwj = (int*) &ret;
	for(int i=0;i<8;++i) ans -= wwj[i];
	return ans;
	
}
inline void solve(int l,int r,int x){
	for(;l % 8 != 0 && l <= r; ++l) if(a[l] > x) a[l] -= x;
	for(;r % 8 != 7 && l <= r; --r) if(a[r] > x) a[r] -= x;
	LL * p = (LL *)(a + l),s = _mm256_set1_epi32(x);
	for(int i = r - l + 1 >> 3;i;) *p = sub(*p,And(greater(*p,s),s)),++p,--i;
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> m;
	for(int i=1;i<=n;++i) std::cin >> a[i];
	for(int i=1,opt,l,r,x;i<=m;++i){
		std::cin >> opt >> l >> r >> x;
		if(opt == 1) solve(l,r,x);
		else std::cout << query(l,r,x) << '\n';
	}
}
// 233