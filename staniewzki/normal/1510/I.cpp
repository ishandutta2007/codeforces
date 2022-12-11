#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // University of Warsaw
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int((x).size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

mt19937 rng(0);
double rd(double l, double r) {
	return uniform_real_distribution<double>(l, r)(rng);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<int> wrong_cnt(n);
	while(m --> 0) {
		string bets;
		cin >> bets;

		double my_bet_prob = 0;
		int min_wrong = *min_element(wrong_cnt.begin(), wrong_cnt.end());
		double sum_weights = 0;
		REP(i, n) {
			double weight = pow(0.9, wrong_cnt[i] - min_wrong);
			sum_weights += weight;
			my_bet_prob += bool(bets[i] == '1') * weight;
		}
		my_bet_prob /= sum_weights;
		debug(wrong_cnt, bets.c_str(), my_bet_prob);

		int my_bet = bool(rd(0, 1) < my_bet_prob);
		cout << my_bet << '\n' << flush;

		char correct_bet;
		cin >> correct_bet;
		REP(i, n)
			if(bets[i] != correct_bet)
				++wrong_cnt[i];
	}
}