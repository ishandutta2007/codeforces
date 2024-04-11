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

constexpr int kSameColumn = 0;
constexpr int kSameRow = 1;
constexpr int kBlack = 0;
constexpr int kWhite = 1;

struct CellData {
	int dnext[2][2] = {{0, 0}, {0, 0}};
	int dprev[2][2] = {{0, 0}, {0, 0}};
};

constexpr int MAX_N = 1005;
int r, c;
CellData cellData[MAX_N][MAX_N];
string arr[MAX_N];
set<int> visited_rows, visited_cols;

struct DfsData {
	DfsData(int x, int y)
		: min_col(y), max_col(y), min_row(x), max_row(x) {}

	void update(int x, int y) {
		min_col = min(min_col, y);
		max_col = max(max_col, y);
		min_row = min(min_row, x);
		max_row = max(max_row, x);
	}

	int min_col, max_col, min_row, max_row;

	friend ostream& operator << (ostream& os, const DfsData& d) {
		os << "(" << d.min_row << ", " << d.max_row << " | " << d.min_col << ", " << d.max_col << ")";
		return os;
	}
};

bool isSolid(const DfsData& data) {
	FORN (row, data.min_row, data.max_row) {
		int first_black_col = data.min_col
			+ cellData[row][data.min_col].dnext[kWhite][kSameRow];
		//LOG(row, first_black_col);
		//LOG(cellData[row][data.min_col].dnext[kWhite][kSameRow],
				//cellData[row][first_black_col].dnext[kBlack][kSameRow],
				//cellData[row][data.max_col].dprev[kWhite][kSameRow],
				//data.max_col - data.min_col);
		if (cellData[row][data.min_col].dnext[kWhite][kSameRow]
				+ cellData[row][first_black_col].dnext[kBlack][kSameRow]
				+ cellData[row][data.max_col].dprev[kWhite][kSameRow]
				!= data.max_col - data.min_col + 1) {
			return false;
		}
	}
	FORN (col, data.min_col, data.max_col) {
		int first_black_row = data.min_row 
		   + cellData[data.min_row][col].dnext[kWhite][kSameColumn];
		if (cellData[data.min_row][col].dnext[kWhite][kSameColumn]
				+ cellData[first_black_row][col].dnext[kBlack][kSameColumn]
				+ cellData[data.max_row][col].dprev[kWhite][kSameColumn]
				!= data.max_row - data.min_row + 1) {
			return false;
		}
	}
	return true;
}

bool isConvex(const DfsData& data) {
	int height = kInf;
	int cur;

	// atas
	height = kInf;
	cur = data.min_col;
	while (cur <= data.max_col) {
		int current_height = cellData[data.min_row][cur].dnext[kWhite][kSameColumn];
		if (current_height > height) {
			break;
		}
		height = current_height;
		++cur;
	}
	while (cur <= data.max_col) {
		int current_height = cellData[data.min_row][cur].dnext[kWhite][kSameColumn];
		if (current_height < height) {
			break;
		}
		height = current_height;
		++cur;
	}
	if (cur != data.max_col + 1) return false;

	// bawah
	height = kInf;
	cur = data.min_col;
	while (cur <= data.max_col) {
		int current_height = cellData[data.max_row][cur].dprev[kWhite][kSameColumn];
		if (current_height > height) {
			break;
		}
		height = current_height;
		++cur;
	}
	while (cur <= data.max_col) {
		int current_height = cellData[data.max_row][cur].dprev[kWhite][kSameColumn];
		if (current_height < height) {
			break;
		}
		height = current_height;
		++cur;
	}
	if (cur != data.max_col + 1) return false;

	// kiri
	height = kInf;
	cur = data.min_row;
	while (cur <= data.max_row) {
		int current_height = cellData[cur][data.min_col].dnext[kWhite][kSameRow];
		if (current_height > height) {
			break;
		}
		height = current_height;
		++cur;
	}
	while (cur <= data.max_row) {
		int current_height = cellData[cur][data.min_col].dnext[kWhite][kSameRow];
		if (current_height < height) {
			break;
		}
		height = current_height;
		++cur;
	}
	if (cur != data.max_row + 1) return false;

	// kanan
	height = kInf;
	cur = data.min_row;
	while (cur <= data.max_row) {
		int current_height = cellData[cur][data.max_col].dprev[kWhite][kSameRow];
		if (current_height > height) {
			break;
		}
		height = current_height;
		++cur;
	}
	while (cur <= data.max_row) {
		int current_height = cellData[cur][data.max_col].dprev[kWhite][kSameRow];
		if (current_height < height) {
			break;
		}
		height = current_height;
		++cur;
	}
	if (cur != data.max_row + 1) return false;

	return true;
}

bool dfs(int x, int y, DfsData* output) {
	if (visited_rows.count(x) || visited_cols.count(y)) return false;
	output->update(x, y);
	FOR (k, 0, 4) {
		auto [nx, ny] = mt(x + dr[k], y + dc[k]);
		if (inRange(nx, 0, r - 1) && inRange(ny, 0, c - 1) && arr[nx][ny] == '#') {
			arr[nx][ny] = '@';
			dfs(nx, ny, output);
		}
	}
	return true;
}

void solve(int tc_num = -1) {
	cin >> r >> c;
	FOR (i, 0, r) {
		cin >> arr[i];
	}

	FOR (i, 0, r) {
		vi lst = {0, 0};
		FOR (j, 0, c) {
			auto& cdata = cellData[i][j];
			if (arr[i][j] == '#') {
				cdata.dprev[kBlack][kSameRow] = ++lst[kBlack];
				lst[kWhite] = 0;
			} else {
				cdata.dprev[kWhite][kSameRow] = ++lst[kWhite];
				lst[kBlack] = 0;
			}
		}
		lst = {0, 0};
		FORD (j, c - 1, 0) {
			auto& cdata = cellData[i][j];
			if (arr[i][j] == '#') {
				cdata.dnext[kBlack][kSameRow] = ++lst[kBlack];
				LOG(i, j, cdata.dnext[kBlack][kSameRow]);
				lst[kWhite] = 0;
			} else {
				cdata.dnext[kWhite][kSameRow] = ++lst[kWhite];
				lst[kBlack] = 0;
			}
		}
	}

	FOR (j, 0, c) {
		vi lst = {0, 0};
		FOR (i, 0, r) {
			auto& cdata = cellData[i][j];
			if (arr[i][j] == '#') {
				cdata.dprev[kBlack][kSameColumn] = ++lst[kBlack];
				lst[kWhite] = 0;
			} else {
				cdata.dprev[kWhite][kSameColumn] = ++lst[kWhite];
				lst[kBlack] = 0;
			}
		}
		lst = {0, 0};
		FORD (i, r - 1, 0) {
			auto& cdata = cellData[i][j];
			if (arr[i][j] == '#') {
				cdata.dnext[kBlack][kSameColumn] = ++lst[kBlack];
				lst[kWhite] = 0;
			} else {
				cdata.dnext[kWhite][kSameColumn] = ++lst[kWhite];
				lst[kBlack] = 0;
			}
		}
	}

	int ans = 0;
	FOR (i, 0, r) {
		FOR (j, 0, c) {
			if (arr[i][j] == '#') {
				DfsData data(i, j);
				bool res = true;
				res &= dfs(i, j, &data);
				LOG(1, res, data);
				res &= isSolid(data);
				LOG(2, res);
				res &= isConvex(data);
				LOG(3, res);
				if (!res) {
					cout << -1 << "\n";
					return;
				}
				++ans;
				FORN (vr, data.min_row, data.max_row) visited_rows.insert(vr);
				FORN (vc, data.min_col, data.max_col) visited_cols.insert(vc);
			}
		}
	}

	if (r - size(visited_rows) > 0 && c - size(visited_cols) == 0) ans = -1;
	else if (c - size(visited_cols) > 0 && r - size(visited_rows) == 0) ans = -1;

	cout << ans << "\n";
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