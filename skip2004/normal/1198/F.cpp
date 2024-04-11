#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l),end##i=(r);i <= end##i;++i)
#define per(i,l,r) for(int i=(r),end##i=(l);i >= end##i;--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull,u64;
typedef unsigned u32;
template<typename _Tp>inline void cmx(_Tp&x,const _Tp&y){if(x<y)x=y;}
template<typename _Tp>inline void cmn(_Tp&x,const _Tp&y){if(x>y)x=y;}
template<typename _Tp>inline void smx(_Tp&x,_Tp&y){if(x<y)swap(x,y);}
template<typename _Tp>inline void smn(_Tp&x,_Tp&y){if(x>y)swap(x,y);}
template<typename _>inline istream&operator,(istream&c,_&x){return c>>x;}
template<typename _>inline ostream&operator,(ostream&o,const _&x){return o<<x;}
istream&in = cin; ostream&out = cout;
const int maxn = 100100;
typedef std::pair<int,int> pii;
std::set<std::pair<int,int>> s[maxn];
std::set<std::pair<int,int>> s2[maxn];
int n,a[maxn],b[maxn];;
std::map<int,int> ans;
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	s[0].emplace(0,0); in,n; int N = n;
	rep(i,1,n){
		in,a[i];
		b[i] = a[i];
	}
	n = 0;
	std::unordered_map<int, int> map;
	for(int i = 1;i <= N;++i) {
		if(++map[a[i]] <= 2) {
			a[++n] = a[i];
		}
	}
	std::mt19937 rd(time(0));
	sort(a + 1, a + n + 1);
	if(n >= 10) for(int i = 1;i <= 5;++i) std::shuffle(a + 5, a + n + 1, rd);
	const int S = 2000000 / n;
	rep(i,1,n) {
		for(auto j : s[i-1]){
			s[i].emplace(std::__gcd(a[i],j.first),j.second);
			s[i].emplace(j.first,std::__gcd(a[i],j.second));
		}
		if(s[i].count({1,1})){
			s[i] = {{1, 1}};
		}
		for(;s[i].size() >= S;) s[i].erase(--s[i].end());
	}
	if(s[n].count({1,1})){
		out,"YES",'\n'; s2[n].emplace(1,1);
		for(int i=n;i>=1;--i) {
			for(;s2[i].size() >= S;) s2[i].erase(--s2[i].end());
			for(auto j : s[i-1]) {
				if(s2[i].count(pii{std::__gcd(a[i],j.first),j.second}))
					s2[i-1].insert(j);
				if(s2[i].count(pii{j.first,std::__gcd(a[i],j.second)}))
					s2[i-1].insert(j);
			}
		}
		int s1 = 0,s2 = 0;
		for(int i=1;i<=n;++i){
			if(::s2[i].count(pii{s1,std::__gcd(s2,a[i])})) {
				if(!ans[a[i]]) ans[a[i]] = 1;
				s2 = std::__gcd(s2,a[i]);
			}
			else s1 = std::__gcd(s1,a[i]), ans[a[i]] = 2;
		}
		for(int i=1;i<=N;++i) {
			out,ans[b[i]] % 2+ 1,' ';
			if(ans[b[i]] == 2) ans[b[i]] = 1;
		}
	} else {
		out,"NO",'\n';
	}
}