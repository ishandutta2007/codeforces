// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2021 Free Software Foundation, Inc.

// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
// #include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}
 
typedef long long ll;
typedef pair<int, int> pi;
 
#define all(x) (x).begin(), (x).end()
#define l first
#define r second
 
const int INF = 1e9 + 1;
const int N = 202000;
 
const ll MOD1 = 998244391;
const ll M1 = 1e6 + 3;
int deg1[N];
 
vector<int> lcp(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    int n = s.size();
    vector<int> L(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k > 0) k--;
        if (pos[i] == n - 1)
            L[n - 1] = -1, k = 0;
        else
        {
            int j = sa[pos[i] + 1];
            while (max(i + k, j + k) < n && s[i + k] == s[j + k])
                k++;
            L[pos[i]] = k;
        }
    }
    return L;
}
 
 
int H[N];
int sp[20][N];
 
int get(int l, int r)
{
    int j = H[r - l + 1];
    return min(sp[j][l], sp[j][r - (1 << j) + 1]);
}
 
void buildsa(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    map<int, int> mm;
    for (int i = 0; i < (int)s.size(); i++)
        mm[s[i]] = -1;
    int x = 0;
    for (int c = 0; c <= s.size(); c++)
    {
        if (mm.find(c) != mm.end())
            mm[c] = x++;
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        pos[i] = mm[s[i]];
    }
    vector<pair<pi, int> > p(s.size());
    for (int j = 1; (1 << j) <= 2 * (int)s.size(); j++)
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            p[i] = {{pos[i], pos[(i + (1 << j) / 2) % s.size()]}, i};
        }
        sort(p.begin(), p.end());
        int x = 0;
        pos[p[0].second] = x;
        for (int i = 1; i < (int)p.size(); i++)
        {
            if (p[i].first != p[i - 1].first) x++;
            pos[p[i].second] = x;
        }
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        sa[pos[i]] = i;
    }
}

vector<int> msepNew(vector<int> &s, vector<int> &sa, vector<int> &isa){
	int cur_best = MOD; //position in s of the current best suffix
	vi res(sz(s), MOD);

	set<array<int, 2>> sort_by_remove; // {position of difference, index in s}
	set<array<int, 2>> sort_by_size; // {index in s, position of difference}

	for(int i = 0; i < sz(s); i++){
		dbg(i);
		if(cur_best == MOD || isa[i] < isa[cur_best]){
			//clear everything
			sort_by_remove.clear();
			sort_by_size.clear();
			cur_best = i;
			dbg("CLEARING");
		}
		else{
			int len_common = get(isa[cur_best], isa[i]-1);
			int pos_diff = i+len_common;
			sort_by_remove.insert(array<int, 2>{pos_diff, i});
			sort_by_size.insert(array<int, 2>{i, pos_diff});
		}

		//remove elements
		while(sz(sort_by_remove)){
			array<int, 2> remove_top = (*sort_by_remove.begin());
			if(remove_top[0] <= i){
				sort_by_remove.erase(remove_top);
				sort_by_size.erase(array<int, 2>{remove_top[1], remove_top[0]});
			}
			else{
				break;
			}
		}

		//determine answer
		if(sz(sort_by_size)){
			res[i] = (*prev(sort_by_size.end()))[0];
		}
		else{
			res[i] = cur_best;
		}
	}

	return res;
}
 
vector<int> msep(vector<int> &s, vector<int> &sa, vector<int> &pos)
{

    vector<int> res(s.size());
 
    int n = s.size();
    int ri = 0;
    int PI = INF;
 
    set<array<int, 3> > waitlist;
    set<array<int, 3> > waitlist_sorted;
 
    auto emplace = [&](int z) { 
        PI = min(PI, z);
        if (PI != INF && PI < z && get(PI, z - 1) >= ri - sa[z])
        {
            waitlist.insert({sa[z] + get(PI, z - 1), z, sa[z]});
            waitlist_sorted.insert({-sa[z], sa[z] + get(PI, z - 1), z});
        }
    };
 
    while (ri < n)
    {
        ri++;
        while (waitlist.size())
        {
            array<int, 3> it = *waitlist.begin();
            int z = it[1];
            if (it[0] >= ri) break;
            waitlist.erase(it);
            waitlist_sorted.erase({-it[2], it[0], it[1]});
        }
        emplace(pos[ri - 1]);
 
        if (waitlist_sorted.size())
        {
            res[ri - 1] = -(*waitlist_sorted.begin())[0];
        }
        else
        {
            res[ri - 1] = sa[PI];
        }
    }
    dbg(s);
    dbg(sa);
    dbg(pos);
    dbg(res);

    vi my_res = msepNew(s, sa, pos);
    dbg(my_res);
    if(res != my_res){
    	ps("ERROR");
    	exit(0);
    }
    return my_res;
}
 
double precomputation_time = 0;
 
vector<int> fast_op(vector<int> s)
{
    double st = clock();
 
    s.push_back(0);
    vector<int> sa(s.size());
    vector<int> pos(s.size());
    buildsa(s, sa, pos);
    vector<int> L = lcp(s, sa, pos);
 
    for (int i = 0; i < (int)s.size(); i++) sp[0][i] = L[i];
    for (int j = 0; j < 20; j++)
        for (int i = 0; i + (1 << j) - 1 < (int)s.size(); i++)
            sp[j][i] = get(i, i + (1 << j) - 1);
 
    s.pop_back();
 
    auto cmp = [&](int l1, int l2, int len)
    {
        if (get(min(pos[l1], pos[l2]), max(pos[l1], pos[l2]) - 1) >= len)
            return 1;
        return 0;
    };
 
    vector<int> min_suf_each_pref = msep(s, sa, pos);
    vector<int> kek_suf_each_pref(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        int len = i + 1 - min_suf_each_pref[i];
        kek_suf_each_pref[i] = min_suf_each_pref[i];
        int j = 0;
        for (j = 0; j < 20; j++)
        {
            ll nc = kek_suf_each_pref[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, kek_suf_each_pref[i], (1ll << j) * len))
                kek_suf_each_pref[i] = nc;
            else
                break;
        }
        for (; j >= 0; j--)
        {
            ll nc = kek_suf_each_pref[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, kek_suf_each_pref[i], (1ll << j) * len))
                kek_suf_each_pref[i] = nc;
        }
    }
 
    precomputation_time += 1.0 * (clock() - st) / CLOCKS_PER_SEC;
 
    deque<pair<int, int> > h;
 
    struct SegTree{
        struct Node
        {
            int l, r;
            ll len;
            ll h1;
        };
 
        vector<Node> tree;
        vector<Node> hashes;
        int pnt;
 
        SegTree(vector<int> s)
        {
            tree.resize(4 * s.size());
            hashes.resize(s.size());
            hashes[0].h1 = s[0];
            for (int i = 1; i < s.size(); i++)
            {
                hashes[i].h1 = (hashes[i - 1].h1 * M1 + s[i]) % MOD1;
            }
            pnt = s.size();
        }
        Node Get(int l, int r)
        {
            Node res;
            res.l = l;
            res.r = r;
            res.len = r - l + 1;
            res.h1 = (hashes[r].h1 - (l ? hashes[l - 1].h1 : 0) * deg1[r - l + 1]) % MOD1;
            res.h1 = (res.h1 + MOD1) % MOD1;
            return res;
        }
        Node Merge(Node L, Node R)
        {
            if (L.len + R.len < N) L.h1 = (L.h1 * deg1[R.len] + R.h1) % MOD1;
            L.len += R.len;
            return L;
        }
        void Set(int pos, Node X, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                tree[V] = X;
                return;
            }
            int M = (L + R) / 2;
            if (pos < M) Set(pos, X, L, M, 2 * V + 1);
            else Set(pos, X, M, R, 2 * V + 2);
            tree[V] = Merge(tree[2 * V + 1], tree[2 * V + 2]);
        }
        void push_front(int l, int r)
        {
            pnt--;
            Set(pnt, Get(l, r), 0, tree.size() / 4, 0);
        }
        Node Get(int chars, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                return Get(tree[V].l, tree[V].l + chars - 1);
            }
            int M = (L + R) / 2;
            if (tree[2 * V + 1].len >= chars)
                return Get(chars, L, M, 2 * V + 1);
            return Merge(tree[2 * V + 1], Get(chars - tree[2 * V + 1].len, M, R, 2 * V + 2));
        }
        Node Get(int chars)
        {
            return Get(chars, 0, tree.size() / 4, 0);
        }
    };
 
    SegTree TT(s);
    for (int i = 1; i <= s.size(); i++)
    {
        int pos1 = min_suf_each_pref[s.size() - i];
        int pos2 = kek_suf_each_pref[s.size() - i];
        int len = s.size() - i + 1 - pos1;
 
        if (pos1 == pos2)
        {
            int LL = min_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, min_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
            continue;
        }
        int t2 = -1;
        int aval = s.size() - i + 1 - pos2 - len;
 
        aval = min(aval, i);
        if (TT.Get(aval).h1 != TT.Get(pos2 + len, pos2 + len + aval - 1).h1)
            t2 = 1;
 
        int shL = aval, shR = i;
        while (t2 == -1 && shL + 1 < shR)
        {
            int sh = (shL + shR) / 2;
            int x1 = TT.Get(sh).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(sh - aval)).h1;
            if (x1 != x2)
                shR = sh;
            else
                shL = sh;
        }
 
        if (t2 == -1 && shR < i)
        {
            int x1 = TT.Get(shR).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(shR - aval)).h1;
            if (x1 != x2)
            {
                if ((x1 - x2 + MOD1) % MOD1 < MOD1 / 2)
                {
                    t2 = 2;
                }
                else
                {
                    t2 = 1;
                }
            }
        }
 
        if (t2 == 1)
        {
            int LL = min_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, min_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
        else
        {
            int LL = kek_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, kek_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
    }
    vector<int> s2;
    for (int j = 0; j < h.size(); j++)
    {
        for (int k = h[j].l; k <= h[j].r; k++)
        {
            s2.push_back(s[k]);
            if (s2.size() == s.size())
                break;
        }
        if (s2.size() == s.size())
            break;
    }
    return s2;
}
 
vector<int> op(vector<int> s)
{
    for (int i = 1; i < s.size(); i++)
    {
        vector<int> h = {INF};
        for (int j = 0; j + i <= s.size(); j++)
        {
            vector<int> t;
            for (int k = 0; k < i; k++)
                t.push_back(s[j + k]);
            h = min(h, t);
        }
        for (int j = 0; j < i; j++)
        {
            s[s.size() - i + j] = h[j];
        }
    }
    return s;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    deg1[0] = 1;
    for (int i = 1; i < N; i++)
        deg1[i] = deg1[i - 1] * M1 % MOD1;
    for (int i = 3; i < N; i++)
        H[i] = (((i - 1) & (i - 2)) == 0) + H[i - 1];
 
    int n;
    cin >> n;
    vector<vector<int> > b(7, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> b[0][i];
    // b[1] - 2
    // b[2] - 5
    // b[3] - 20
    // b[4] - 230
    // b[5] - 26795
    // b[6] - stable
    for (int i = 1; i < 6; i++) b[i] = fast_op(b[i - 1]);
    int pos = 0;
    while (pos + 1 < n && b[0][pos + 1] <= b[0][pos]) pos++;
    for (int i = 0; i < pos; i++) b[6][i] = b[0][i];
    for (int i = pos; i < n; i++) b[6][i] = b[0][pos];
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        j--;
        i = min(i, 6);
        cout << b[i][j] << "\n";
    }
    return 0;
 
}