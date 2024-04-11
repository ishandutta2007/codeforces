#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int _NN;

struct interval {
  ll l, r;
  interval(ll l, ll r) : l(l), r(r) {}
  bool contains(ll x) {
    return l <= x && x < r;
  }
  ll length() {
    return r - l;
  }
  interval shrink(ll o, ll s) {
    return interval(min(r, l + o), min(r, l + o + s));
  }
};

vector<interval> splitIntervals(vector<interval> c, ll o, ll s) {
  vector<interval> r;
  for (interval &it : c) {
    if (s > 0 && it.length() - o > 0)
      r.push_back(it.shrink(o, s));
    s -= max(0LL, min(s, it.length() - o));
    o -= min(o, it.length());
  }
  return r;
}

bool contains(vector<interval> c, ll x) {
  for (interval &it : c)
    if (it.contains(x))
      return true;
  return false;
}

struct state {
  ll s[2] = {0, 0};
  vector<vector<interval>> c;
  state(ll N): c(2) {
    s[1] = N;
    c[1].emplace_back(1, N + 1);
  }
  state(vector<vector<vector<interval>>> &cs): c(2) {
    for (int g = 0; g < 2; g++)
      for (vector<interval> &c : cs[g])
        add(g, c);
  }
  void add(int g, interval it) {
    s[g] += it.length();
    c[g].push_back(it);
  }
  void add(int g, vector<interval> &c) {
    for (interval &it : c)
      add(g, it);
  }
  vector<vector<vector<interval>>> split() {
    vector<vector<vector<interval>>> r(2);
    for (int g = 0; g < 2; g++) {
      int s1 = (s[g] + g) / 2, s2 = s[g] - s1;
      r[g].push_back(splitIntervals(c[g], 0, s1));
      r[g].push_back(splitIntervals(c[g], s1, s2));
    }
    return r;
  }
  ll size() {
    return s[0] + s[1];
  }
  vector<ll> remaining() {
    vector<ll> r;
    for (int g = 0; g < 2; g++)
      for (interval &it : c[g])
        for (ll v = it.l; v < it.r; v++)
          r.push_back(v);
    return r;
  }
};


bool que(vector<ll> v){
	cout << "? ";
	cout << v.size() << ' ';
	for(auto x : v)cout << x << ' ';
	cout << endl;
	string s; cin >> s;
	if(s == "NO")return 0;
	else return 1;

}

int recieve(int X, vector<vector<vector<interval>>> &c, state &S){
	vector<ll> V = S.remaining();
	vector<ll> toQ;
	for(auto x : V){
		if(contains(c[0][0],x) || contains(c[1][0],x))toQ.push_back(x);
	}
	return que(toQ);
}

std::pair<int, int> solve(int N, int X = -1) {
  state s(N);
  while (s.size() > 3) {
    vector<vector<vector<interval>>> c = s.split();
    int b = recieve(X,c,s);
    c[0].erase(c[0].begin() + b);
    swap(c[0][0], c[1][b]);
    s = state(c);
  }
  vector<ll> r = s.remaining();
  if ((int) r.size() == 3) {
    int b1 = 1, b2;
    for (int i = 0; i < 2 && b1; i++){
	    b1 = que({r[0],r[1]});
    }
    if (!b1){
	    b2 = que({r[0]});
    }
    r.erase(r.begin() + (b1 ? 2 : (b2 ? 1 : 0)));
  }
  return {r[0], r.back()};
}

std::pair<int, int> decode(int N) {
  return solve(N);
}

int main(){
	int n; cin >> n;
	_NN =n;
	pair<int,int> x = decode(n);
	cout << "! " << x.first << endl;
	string s; cin >> s;
	if(s == ":)")return 0;
	else {
		cout << "! " << x.second << endl;
		cin >> s;
		assert(s == ":)");
		return 0;
	}
}