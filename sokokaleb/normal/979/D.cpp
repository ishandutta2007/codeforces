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

class Node {
	public:
	Node* to[2] = {nullptr, nullptr};
	int smol = INF;

	Node* getNext(int y);
	void update(int val) {
		smol = min(smol, val);
	}
};

constexpr int MAX_N = 100005;
bitset<MAX_N> sudah;
int q;

int sz = 100000;
deque<Node> node(100000);
Node* ROOT[100001];

Node* ask() {
	if (sz == SIZE(node)) {
		node.resize(sz * 2);
	}
	return &node[sz++];
}

Node* Node::getNext(int y) {
	if (to[y] == nullptr) {
		to[y] = ask();
	}
	return to[y];
}

void insert(Node* ROOT, int x) {
	Node* now = ROOT;
	now->update(x);
	FORD (i, 16, 0) {
		int y = (x >> i) & 1;
		now = now->getNext(y);
		now->update(x);
	}
	return;
}

int jawab(Node* ROOT, int X, int S) {
	Node* now = ROOT;
	//cerr << X << " " << S << endl;
	FORD (i, 16, 0) {
		//cerr << "LEVEL " << i << endl;
		int y = (X >> i) & 1;
		bool ada = 0;
		FOR (zz, 0, 2) {
			y ^= 1;
			//cerr << "Y = " << y << endl;
			if (now->to[y] == nullptr) continue;
			//cerr << "PASS 1" << endl;
			Node* nex = now->getNext(y);
			if (X + nex->smol > S) continue;
			//cerr << "PASS 2" << endl;
			ada = 1;
			now = nex;
			break;
		}
		if (!ada) return -1;
	}
	return now->smol;
}

void update(int& ans, int res, int X) {
	if (ans == -1) ans = res;
	else if (res == -1);
	else {
		if ((res ^ X) > (ans ^ X)) ans = res;
	}
}

int main(int argc, char** argv) {
	__INIT_CC__
	FORN (i, 1, 100000) {
		ROOT[i] = &node[i - 1];
	}
	//FORN (i, 1, 100000) {
		//FORN (z, 1, i) {
			//if (z * z > i) break;
			//if (i % z == 0) {
				//int y = i / z;
				//insert(ROOT[z], i);
				//if (y != z) {
					//insert(ROOT[y], i);
				//}
			//}
		//}
	//}
	//cout << sz << endl;
	//return 0;
	cin >> q;
	FORN (tc, 1, q) {
		int op;
		cin >> op;
		if (op == 1) {
			int u;
			cin >> u;
			if (sudah.test(u));
			else {
				sudah.set(u, 1);
				FORN (i, 1, u) {
					if (i * i > u) break;
					if (u % i == 0) {
						int j = u / i;
						insert(ROOT[i], u);
						if (j != i) {
							insert(ROOT[j], u);
						}
					}
				}
			}
		} else {
			int X, K, S;
			cin >> X >> K >> S;
			int ans = -1;
			FORN (d1, 1, X) {
				if (d1 * d1 > X) break;
				if (X % d1 == 0) {
					int d2 = X / d1;
					if (d1 % K == 0) {
						//cerr << "COBA " << d1 << endl;
						update(ans, jawab(ROOT[d1], X, S), X);
					}
					if (d2 == d1) continue;
					if (d2 % K == 0) {
						//cerr << "COBA " << d2 << endl;
						update(ans, jawab(ROOT[d2], X, S), X);
					}
				}
			}
			cout << ans << "\n";
		}
	}
}