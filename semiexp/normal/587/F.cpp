#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

namespace
{
template <typename Iterator, typename T>
void induced_sort(Iterator start, Iterator end, T lower, T higher, std::vector<bool> &is_s, std::vector<int> count_ls, std::vector<int> &sto)
{
	int n = end - start, k = higher - lower;

	for (int i = 0; i < k; ++i) count_ls[i * 2 + 1] = count_ls[i * 2 + 2];
	if (!is_s[n - 1]) sto[count_ls[(int)(*(end - 1) - lower) * 2]++] = n - 1; // for $
	for (int i = 1; i <= n; ++i) if (sto[i] > 0 && !is_s[sto[i] - 1]) {
		sto[count_ls[(int)(*(start + sto[i] - 1) - lower) * 2]++] = sto[i] - 1;
	}
	for (int i = 0; i < n; ++i) if (sto[i] >= 0 && is_s[sto[i]]) {
		sto[i] = -1;
	}
	for (int i = n; i >= 1; --i) if (sto[i] > 0 && is_s[sto[i] - 1]) {
		sto[--count_ls[(int)(*(start + sto[i] - 1) - lower) * 2 + 1]] = sto[i] - 1;
	}
}
template <typename Iterator>
bool compare_lms(Iterator start, std::vector<int> &lms_idx, int i, int j)
{
	do {
		if (*(start + i) != *(start + j)) return false;
		++i; ++j;
	} while (lms_idx[i] == -1 && lms_idx[j] == -1);
	return lms_idx[i] != -1 && lms_idx[j] != -1;
}
template <typename Iterator, typename T>
std::vector<int> sais(Iterator start, Iterator end, T lower, T higher)
{
	// [start, end) [lower, higher)
	int n = end - start, k = higher - lower;
	if (n == 0) return{ 0 };
	if (n == 1) return{ 1, 0 };
	std::vector<bool> is_s(n + 1, false);
	is_s[n] = true;
	for (int i = n - 1; i != 0; --i) {
		if (*(start + i - 1) < *(start + i)) is_s[i - 1] = true;
		else if (*(start + i - 1) == *(start + i)) is_s[i - 1] = is_s[i];
	}

	std::vector<int> count_ls(2 * k + 1, 0);
	count_ls[0] = 1;
	for (Iterator it = start; it != end; ++it) {
		if (is_s[it - start]) ++count_ls[(int)(*it - lower) * 2 + 2];
		else ++count_ls[(int)(*it - lower) * 2 + 1];
	}
	for (int i = 1; i <= 2 * k; ++i) count_ls[i] += count_ls[i - 1];

	std::vector<int> lms_store(k, 0);
	for (int i = 0; i < k; ++i) lms_store[i] = count_ls[i * 2 + 2];
	std::vector<int> vec_is(n + 1, -1), lms_idx(n, -1);
	int n_lms = 0;
	for (int i = 1; i < n; ++i) {
		if (is_s[i] && !is_s[i - 1]) { // a[i] is LMS
			vec_is[--lms_store[(int)(*(start + i) - lower)]] = i;
			lms_idx[i] = n_lms++;
		}
	}

	induced_sort(start, end, lower, higher, is_s, count_ls, vec_is);

	std::vector<int> nxt_str(n_lms, 0); int ord = -1, last = -1;
	for (int i = 1; i <= n; ++i) {
		int p = vec_is[i];
		if (lms_idx[p] != -1) {
			if (ord == -1 || !compare_lms(start, lms_idx, p, last)) ++ord;
			nxt_str[lms_idx[p]] = ord;
			last = p;
		}
	}

	std::vector<int> sa_sub = sais(nxt_str.begin(), nxt_str.end(), 0, ord + 1);
	for (int i = 0; i < k; ++i) lms_store[i] = count_ls[i * 2 + 2];
	for (int i = 1; i <= n; ++i) vec_is[i] = -1;
	n_lms = 0;
	for (int i = 1; i < n; ++i) {
		if (is_s[i] && !is_s[i - 1]) { // a[i] is LMS
			lms_idx[n_lms++] = i;
		}
	}
	for (int i = n_lms; i >= 1; --i) {
		int p = lms_idx[sa_sub[i]];
		vec_is[--lms_store[(int)(*(start + p) - lower)]] = p;
	}
	induced_sort(start, end, lower, higher, is_s, count_ls, vec_is);
	vec_is[0] = n;
	return vec_is;
}
std::vector<int> compute_sa_rev(const std::vector<int> &sa)
{
	std::vector<int> sa_rev(sa.size(), -1);
	for (int i = 0; i < sa.size(); ++i) sa_rev[sa[i]] = i;
	return sa_rev;
}
template <typename Iterator>
std::vector<int> compute_lcp(Iterator start, Iterator end, const std::vector<int> &sa, const std::vector<int> &sa_rev)
{
	int h = 0, n = end - start, j;
	std::vector<int> ret(n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = sa[sa_rev[i] - 1]; j + h < n && i + h < n && *(start + j + h) == *(start + i + h); ++h);
		ret[sa_rev[i] - 1] = h;
		if (h > 0) --h;
	}
	return ret;
}
class substring_info
{
public:
	substring_info() : lcp_seg_(nullptr), size_(0) {}

	// lower, higher should specify that each character is within the range [lower, higher).
	template <typename Iterator, typename T>
	substring_info(Iterator start, Iterator end, T lower, T higher, std::vector<int> &saa)
	{
		len_ = end - start;
		std::vector<int> sa = sais(start, end, lower, higher);
		sa_rev_ = compute_sa_rev(sa);
		std::vector<int> lcp = compute_lcp(start, end, sa, sa_rev_);
		for (size_ = 1; size_ < lcp.size(); size_ <<= 1);

		lcp_seg_ = new int[size_ * 2];
		for (int i = 0; i < size_; ++i) {
			if (i < lcp.size()) lcp_seg_[i + size_] = lcp[i];
			else lcp_seg_[i + size_] = 0x7fffffff;
		}
		for (int i = size_ - 1; i >= 1; --i) lcp_seg_[i] = std::min(lcp_seg_[i * 2], lcp_seg_[i * 2 + 1]);
	}
	~substring_info() { delete[] lcp_seg_; }

	// Returns the length of the longest common prefix of substrings S[p..] and S[q..]
	int substring_common_prefix(int p, int q)
	{
		if (p == q) return len_ - p;
		int pl = sa_rev_[p], ql = sa_rev_[q];
		if (pl > ql) std::swap(pl, ql);
		return range_min(pl, ql);
	}

	// Compare substrings S[p...(p+l)] and S[q...(q+l)].
	// -1: the latter is larger.
	// 0 : both are equal.
	// 1 : the former is larger.
	int compare_substring(int p, int q, int l)
	{
		if (p == q) return 0;
		int pl = sa_rev_[p], ql = sa_rev_[q];
		int ans = (pl < ql) ? -1 : 1;
		if (pl > ql) std::swap(pl, ql);
		if (range_min(pl, ql) >= l) return 0;
		return ans;
	}
private:
	int range_min(int p, int q)
	{
		p += size_; q += size_;
		int ret = 0x7fffffff;
		while (p != q) {
			if (p & 1) ret = std::min(ret, lcp_seg_[p++]);
			if (q & 1) ret = std::min(ret, lcp_seg_[--q]);
			p >>= 1; q >>= 1;
		}
		return ret;
	}
	std::vector<int> sa_rev_;
	int *lcp_seg_;
	int len_, size_;
};
}

struct segtree
{
	static const int DEPTH = 18;
	static const int N = 1 << DEPTH;

	int data[2 * N];

	segtree() {
		for (int i = 0; i < 2 * N; ++i) data[i] = 0;
	}
	void append(int p, int v) {
		p += N;
		while (p) {
			data[p] += v;
			p >>= 1;
		}
	}
	int query(int L, int R) {
		int ret = 0;
		L += N; R += N;
		while (L < R) {
			if (L & 1) ret += data[L++];
			if (R & 1) ret += data[--R];
			L >>= 1; R >>= 1;
		}
		return ret;
	}
};

int N, Q;
string S[101010];
char in[101010];

vector<int> sa, sa_rev;
vector<int> whose;
vector<bool> is_fst;

const int kThreshold = 400;
vector<int> heavy;
int hidx[101010];
int heavy_cnt[100000 / 400][202020];
i64 heavy_sol[101010];

int lf[101010], rg[101010];
segtree seg;
int loc[101010];

i64 ans[101010];
vector<pair<int, int> > bef[101010], aft[101010];

void range_add(int l, int r)
{
	seg.append(l, 1);
	seg.append(r, -1);
}
int point_query(int p)
{
	return seg.query(0, p + 1);
}

void proc(vector<pair<int, int> > &seq, int w)
{
	for (auto a : seq) {
		int target = a.second, str = a.first;
		if (hidx[str] != -1) {
			ans[target] += w * heavy_sol[str];
		} else {
			i64 ret = 0;
			for (int i = loc[str]; i < loc[str + 1] - 1; ++i) {
		//		printf("for %d: %d\n", str, sa_rev[i]);
				ret += point_query(sa_rev[i]);
			}
		//	printf("%d appeared %d\n", str, ret);
			ans[target] += w * ret;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%s", in);
		S[i] = in;
	}

	vector<int> ss;
	for (int i = 0; i < N; ++i) {
		heavy_sol[i] = 0;
		ss.push_back(100 + i);
		loc[i] = ss.size();
		for (char c : S[i]) ss.push_back(c - 'a');
	}
	loc[N] = ss.size() + 1;

	sa = sais(ss.begin(), ss.end(), 0, N + 110);
	sa_rev = compute_sa_rev(sa);
	substring_info sub(ss.begin(), ss.end(), 0, N + 110, sa);

	int last = -1, cnt = 0;
	for (int i = 0; i < ss.size(); ++i) {
		if (ss[i] >= 100) {
			last = ss[i] - 100;
			cnt = 0;
			whose.push_back(-1);
			is_fst.push_back(false);
		} else {
			whose.push_back(last);
			is_fst.push_back(cnt++ == 0);
		}
	}
	whose.push_back(-1);
	is_fst.push_back(false);

	int hid = 0;
	for (int i = 0; i < N; ++i) if (S[i].size() >= kThreshold) {
		hidx[i] = hid++;
		heavy.push_back(i);
		for (int j = 0; j <= ss.size(); ++j) {
			heavy_cnt[hidx[i]][j] = 0;
		}
	} else hidx[i] = -1;
	for (int i = 0; i < sa.size(); ++i) {
		if (whose[sa[i]] >= 0 && hidx[whose[sa[i]]] != -1) {
			++heavy_cnt[hidx[whose[sa[i]]]][i + 1];
		}
	}
	for (int i = 0; i < hid; ++i) {
		for (int j = 1; j <= sa.size(); ++j) heavy_cnt[i][j] += heavy_cnt[i][j - 1];
	}
/*	for (int i = 0; i < hid; ++i) {
		printf("%d: ", heavy[i]);
		for (int j = 0; j <= ss.size(); ++j) printf("%d ", heavy_cnt[i][j]);
		puts("");
	} */
	for (int i = 0; i < sa.size(); ++i) if (is_fst[sa[i]]) {
		int strid = whose[sa[i]];
		int len = S[strid].size();
		{
			int left = 0, right = i;
			while (left < right) {
				int mid = (left + right) / 2;
				if (sub.substring_common_prefix(sa[mid], sa[i]) >= len) {
					right = mid;
				} else {
					left = mid + 1;
				}
			}
			lf[strid] = left;
		}
		{
			int left = i, right = sa.size() - 1;
			while (left < right) {
				int mid = (left + right + 1) / 2;
				if (sub.substring_common_prefix(sa[mid], sa[i]) >= len) {
					left = mid;
				} else {
					right = mid - 1;
				}
			}
			rg[strid] = left;
		}
	//	printf("%d: %d %d\n", strid, lf[strid], rg[strid]);
	}

	for (int i = 0; i < Q; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		ans[i] = 0;
		--l; --r; --k;
		bef[l].push_back({ k, i });
		aft[r].push_back({ k, i });
	}
	for (int i = 0; i < N; ++i) {
		proc(bef[i], -1);

		range_add(lf[i], rg[i] + 1);
		for (int hv : heavy) {
			int hi = hidx[hv];
			heavy_sol[hv] += heavy_cnt[hi][rg[i] + 1] - heavy_cnt[hi][lf[i]];
		}
		proc(aft[i], 1);
	}
	for (int i = 0; i < Q; ++i) printf("%lld\n", ans[i]);
	return 0;
}