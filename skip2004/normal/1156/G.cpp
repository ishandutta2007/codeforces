#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;
using std::string;
using std::vector;
const int maxn = 200200;
typedef long long ll;
struct name {
	int id;
	inline name() {}
	inline name(string s) {
		s.resize(4);
		id = * (int*) s.data();
	}
};
inline int operator < (const name & x, const name & y) {
	return x.id < y.id;
}
inline int operator != (const name & x, const name & y) {
	return x.id != y.id;
}
static std::mt19937 rd(time(0));
struct val_tree {
	static const int mod = 998244353;
	int hash_val;
	int is_leave;
	char oper_type;
	val_tree * left, * right;
	name id;
	inline val_tree() {
		hash_val = rd() % mod;
		is_leave = 1;
		oper_type = 0;
		left = right = nullptr;
		id.id = 0;
	}
	inline val_tree(val_tree * le, char op, val_tree * ri) {
		hash_val = ((ll) le -> hash_val * 234234 + (ll) ri -> hash_val * 114514 + op) % mod;
		is_leave = 0;
		oper_type = op;
		left = le;
		right = ri;
		id.id = 0;
	}
};
std::map<name, val_tree *> map;
std::map<int, name> oper;
vector<string> operators;
std::set<name> set = {name("res")};
inline name gen() {
	do {
		string s;
		for(int i = 0;i < 4;++i) s += char(rd() % 26 + 'a');
		name x(s);
		if(!set.count(x)) {
			set.emplace(x);
			return x;
		}
	} while(1);
}
string to_string(name x) {
	char ch[5] = {};
	memcpy(ch, &x, 4);
	return (string) ch;
}
inline name dfs(val_tree * x, bool is_last = 0) {
	if(oper.count(x -> hash_val)) {
		return oper[x -> hash_val];
	}
	name le = dfs(x -> left), ri = dfs(x -> right);
	name now = is_last ? name("res") : gen();
	operators.emplace_back(to_string(now) + "=" + to_string(le) + x -> oper_type + to_string(ri));
	return oper[x -> hash_val] = now;
}
inline val_tree * get(name x) {
	if(map.count(x)) return map[x];
	val_tree * o = map[x] = new val_tree();
	o -> id = x;
	set.emplace(x);
	oper[o -> hash_val] = x;
	return o;
}
inline bool is_oper(char x) {
	return x == '=' || x == '$' || x == '^' || x == '#' || x == '&';
}
inline vector<string> split(string x) {
	vector<string> vec;
	string now;
	for(char i : x) {
		if(is_oper(i)) {
			vec.emplace_back(now);
			now = i;
			vec.emplace_back(now);
			now = "";
		} else {
			now += i;
		}
	}
	vec.emplace_back(now);
	return vec;
}
inline void do_it(string x) {
	vector<string> vc = split(x);
	if(vc.size() == 3) {
		if(vc[0] != vc[2]) 
			map[name(vc[0])] = get(name(vc[2]));
	} else {
		val_tree * v0 = get(name(vc[2])), * v1 = get(name(vc[4]));
		map[name(vc[0])] = new val_tree(v0, vc[3].back(), v1); 
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;++i) {
		string s;
		cin >> s;
		do_it(s);
	}
	if(map.count(name("res"))) {
		name out = dfs(map[name("res")], 1);
		if(operators.empty() && out != name("res")) {
			cout << 1 << '\n';
			cout << "res=" << to_string(out) << '\n';
			return 0;
		}
		cout << operators.size() << '\n';
		for(string i : operators) {
			cout << i << '\n';
		}
	} else {
		cout << 0 << '\n';
	}
}