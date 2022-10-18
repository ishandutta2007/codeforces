#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class I> vi lis3(I begin, I end) {
	struct {bool operator()(I i, I j) const {return *i<*j;}} cmp;
	if(begin == end) return {};
	vector<I> idx, back(end-begin);
	idx.push_back(end);
	for(I it = begin; it != end; ++it) {
		// upper_bound if non-decreasing rather than increasing
		auto b = upper_bound(idx.begin() + 1, idx.end(), it, cmp);
		back[it-begin] = *(b-1);
		if(b == idx.end()) idx.push_back(it); else *b = it;
	}
	int len = sz(idx)-1, last = (int)(idx.back()-begin);
	vi ind(len);
	while(len) ind[--len] = last, last = (int)(back[last]-begin);
	return ind;
}

int main() {
	cin.sync_with_stdio(false);
	int N, T;
	cin >> N >> T;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	if (N*N*2 + 2 < T) {
		int M = N*N*2+1;
		vi b(M*N);
		rep(i,0,M) rep(j,0,N) b[i*N+j] = a[j];
		int sz_a = sz(lis3(all(b)));
		++M;
		rep(j,0,N) b.push_back(a[j]);
		int sz_b = sz(lis3(all(b)));
		cout << (T - M) * (sz_b - sz_a) + sz_b << endl;
	}
	else {
		vi b(T*N);
		rep(i,0,T) rep(j,0,N) b[i*N+j] = a[j];
		cout << sz(lis3(all(b))) << endl;
	}

}