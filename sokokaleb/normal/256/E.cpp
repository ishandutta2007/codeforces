#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v4.0

const int MOD = 777777777;

struct Matrix {
	int mat[3][3];

	Matrix() {
		RESET(mat, 0);
	}

	void set(int r, int c, int val = 1) {
		mat[r][c] = val;
	}

	void identity() {
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				mat[i][j] = (i == j ? 1 : 0);
			}
		}
	}

	Matrix& operator *= (const Matrix& O) {
		Matrix tmp;
		FOR (k, 0, 3) {
			FOR (i, 0, 3) {
				FOR (j, 0, 3) {
					tmp.mat[i][j] += (1LL * this->mat[i][k] * O.mat[k][j]) % MOD;
					if (tmp.mat[i][j] >= MOD) {
						tmp.mat[i][j] -= MOD;
					}
				}
			}
		}
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				this->mat[i][j] = tmp.mat[i][j];
			}
		}
		return *this;
	};

	friend Matrix operator * (const Matrix& A, const Matrix& B) {
		Matrix res = A;
		res *= B;
		return res;
	}

	friend ostream& operator << (ostream& os, const Matrix& O) {
		os << "START OF MTX\n";
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				os << setw(4) << O.mat[i][j];
			}
			os << "\n";
		}
		os << "END OF MTX\n";
		return os;
	}
};

struct STNode {
	Matrix c;

	void merge(const STNode& A, const STNode& B) {
		c = A.c * B.c;
	}
};

STNode st[77780 << 2];
Matrix M[4];
int init[3];
int n, m;

void build(int node, int l, int r) {
	if (l == r) {
		st[node].c = M[0];
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	build(A, l, mid);
	build(B, mid + 1, r);
	st[node].merge(st[A], st[B]);
}

void update(int node, int l, int r, int p, const Matrix& v) {
	if (l == r && r == p) {
		st[node].c = v;
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= p) update(A, l, mid, p, v);
	if (mid + 1 <= p) update(B, mid + 1, r, p, v);
	st[node].merge(st[A], st[B]);
}

STNode query(int node, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return st[node];
	}
	STNode L, R, res;
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= a) L = query(A, l, mid, a, b);
	else L.c.identity();
	if (mid + 1 <= b) R = query(B, mid + 1, r, a, b);
	else R.c.identity();
	res.merge(L, R);
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m;
	FOR (i, 0, 3) {
		FOR (j, 0, 3) {
			cin >> M[0].mat[i][j];
		}
	}
	M[1] = M[2] = M[3] = M[0];
	FORN (k, 1, 3) {
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				M[k].mat[i][j] = (j == k - 1 ? M[k].mat[i][j] : 0);
			}
		}
	}
	if (n > 1) {
		build(1, 2, n);
	}
	fill(init, init + 3, 1);
	FOR (q, 0, m) {
		int v, t;
		cin >> v >> t;
		if (v != 1) {
			update(1, 2, n, v, M[t]);
		} else {
			if (t == 0) {
				fill(init, init + 3, 1);
			} else {
				fill(init, init + 3, 0);
				init[t - 1] = 1;
			}
		}
		if (n == 1) {
			cout << init[0] + init[1] + init[2] << "\n";
		} else {
			STNode s = query(1, 2, n, 2, n);
			int jum = 0;
			FOR (i, 0, 3) {
				FOR (j, 0, 3) {
					jum += (1LL * init[j] * s.c.mat[j][i]) % MOD;
					if (jum >= MOD) jum -= MOD;
				}
			}
			//FORN (i, 2, n) {
				//cout << query(1, 2, n, i, i).c << "\n";
			//}
			cout << jum << "\n";
		}
	}
}