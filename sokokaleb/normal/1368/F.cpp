#include <bits/stdc++.h>
using namespace std;

namespace {

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

namespace logging {
	template<typename T>
	std::ostream& operator << (std::ostream& os, vector<T> vec) {
		bool first = true;
		for (const T& v : vec) {
			os << (first ? "" : " ") << v;
			first = false;
		}
		return os;
	}

	template<typename A, typename B>
	std::ostream& operator << (std::ostream& os, pair<A, B> p) {
		os << "(" << p.first << ", " << p.second << ")";
		return os;
	}

#ifdef DEBUG
	constexpr bool enable_logging = true;
#else
	constexpr bool enable_logging = false;
#endif

	constexpr bool IsLiteralValue(const string_view value_str) {
		bool is_digit = false;
		for (const auto c : "0123456789") {
			is_digit |= value_str[0] == c;
		}
		return (value_str.front() == '\'' && value_str.front() == '\'') ||
			(value_str.front() == '"' && value_str.front() == '"') || is_digit;
	}

#define IS_LITERAL_VALUE(value) IsLiteralValue(#value)
#define VAR_STR(value) #value

	using LabelStr = string;
	using ValueStr = string;
	using DebugPair = pair<LabelStr, ValueStr>;

	vector<ValueStr> ToStringValues() {
		return vector<ValueStr>();
	}

	template <typename U, typename ...Ts>
	vector<ValueStr> ToStringValues(const U& arg, Ts... args) {
		auto vec = ToStringValues(args...);
		ostringstream oss;
		oss << arg;
		vec.push_back(oss.str());
		return vec;
	}

	vector<LabelStr> ToStringLabels(const string& labels) {
		vector<LabelStr> result;
		string current = "";
		bool in_string = false;
		for (const auto& c : labels) {
			if (in_string) {
				current.push_back(c);
				if (c == '"') {
					in_string = false;
				}
			} else if (c == ',') {
				result.push_back(current);
				current = "";
			} else if (c != ' ') {
				current.push_back(c);
				if (c == ' ') {
					in_string = true;
				}
			}
		}
		if (size(current) > 0) {
			result.push_back(current);
		}
		for (auto& c : result) {
			if (IsLiteralValue(c)) c = "";
		}
		return result;
	}


	template <typename ...Ts>
	vector<DebugPair>ToDebugPairs(
			const string& labels, Ts... args) {
		auto label_vec = ToStringLabels(labels);
		auto str_vec = ToStringValues(args...);
		reverse(ALL(str_vec));
		assert(size(str_vec) == size(label_vec));

		vector<DebugPair> result;
		for (int i = 0; i < size(str_vec); ++i) {
			result.emplace_back(label_vec[i], str_vec[i]);
		}
		return result;
	}

#define TO_DEBUG_PAIRS(args_labels, ...) \
	::logging::ToDebugPairs(args_labels, __VA_ARGS__)

	void __log(const int line_number, vector<DebugPair> debug_pairs) {
		if constexpr (enable_logging) {
			cerr << ">> [row " << line_number << "]: ";
			bool first_element = true;
			for (const auto [label, value] : debug_pairs) {
				if (!first_element) {
					cerr << ", ";
				}
				if (size(label) > 0) {
					cerr << label << " = ";
				}
				cerr << value;
				first_element = false;
			}
			cerr << endl;
		}
	}
}  // namespace logging

#define LOG(...) \
	if constexpr (::logging::enable_logging) \
	  ::logging::__log(__LINE__, TO_DEBUG_PAIRS(#__VA_ARGS__, __VA_ARGS__));\
	else {};

constexpr int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
constexpr int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
constexpr double eps = 1e-9;
constexpr int kInf = 0x7FFFFFFF;
constexpr ll kInfll = 0x7FFFFFFFFFFFFFFFLL;
constexpr double pi = acos(-1);

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

}  // namespace

namespace solver {

constexpr bool kHasMultipleCases = false;
int n;
int res[1005];

ii CalculateK(int n) {
	FORN (k, 2, n - 2) {
		int verboden = k + 1;
		verboden += (n - verboden) / k;
		res[k] = n - verboden;
	}
	auto it = max_element(res, res + n);
	return {distance(res, it), *it};
}

set<int> harus_taro;
set<int> dah_taro;

int GenerateMove(int k) {
	cout << k;
	queue<int> Q;
	int current_ans = 0;
	FOR (i, 0, k) {
		int now;
		if (!harus_taro.empty()) {
			now = *harus_taro.begin();
			harus_taro.erase(harus_taro.begin());
			++current_ans;
		} else {
			now = *dah_taro.begin();
			dah_taro.erase(dah_taro.begin());
		}
		cout << " " << now;
		Q.push(now);
	}
	cout << endl;
	while (!Q.empty()) dah_taro.insert(take(Q));
	return current_ans;
}

int ReadResponse(int n, int k) {
	int x;
	cin >> x;
	int current_ans = 0;
	if (x == -1) exit(0);
	for (int i = 0; i < k; ++i) {
		if (dah_taro.count(x)) {
			dah_taro.erase(x);
			harus_taro.insert(x);
			--current_ans;
		}
		++x;
		if (x == n + 1) x = 1;
	}
	return current_ans;
}

void solve(int tc_num = -1) {
	cin >> n;

	if (n <= 3) {
		cout << 0 << endl;
		return;
	}

	auto [k, ans] = CalculateK(n);
	LOG(k, ans);
	assert(k > 0);
	for (int pos = 1; pos <= n; pos += k) {
		FORN (z, pos + 1, pos + k - 1) {
			LOG(z);
			harus_taro.insert(z);
		}
	}

	int current_ans = 0;
	while (current_ans < ans) {
		current_ans += GenerateMove(k);
		int x;
		current_ans += ReadResponse(n, k);
	}
	cout << 0 << endl;
}

}  // namespace solver

//using sokokaleb's template v7.0

int main(int argc, char** argv) {
	__INIT_CC__
	if constexpr (solver::kHasMultipleCases) {
		int num_tc;
		cin >> num_tc;
		FORN (i, 1, num_tc) {
			solver::solve(num_tc);
		}
	} else {
		solver::solve();
	}
}