#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <cassert>

using namespace std;

const double INF = 1e60;
const double eps = 1e-12;

class Raffle {
public:
	int size, buying, id;
	int value;
	double next_buy, last_buy;

	Raffle(int value, int size, int id) : value(value), size(size), id(id) {
		buying = 0;
		update();
	}

	inline bool friend operator < (const Raffle &a, const Raffle &b) {
		return a.id < b.id;
	}

	void update() {
		if (buying < size) {
			next_buy = 1. * (buying + 1) / (size + buying + 1)
					- 1. * buying / (size + buying);
			next_buy *= value;
		} else {
			next_buy = 0;
		}

		if (buying > 0) {
			last_buy = 1. * buying / (size + buying)
					- 1. * (buying - 1) / (size + buying - 1);
			last_buy *= value;
		} else {
			last_buy = INF;
		}
	}

	double gain() {
		return 1. * value * buying / (buying + size);
	}
};

class CompareLast {
public:
	bool operator() (const Raffle &a, const Raffle &b) {
		if (fabs(a.last_buy - b.last_buy) > eps) {
			return a.last_buy < b.last_buy;
		} else {
			return a.id < b.id;
		}
	}
};

class CompareNext {
public:
	bool operator() (const Raffle &a, const Raffle &b) {
		if (fabs(a.next_buy - b.next_buy) > eps) {
			return a.next_buy < b.next_buy;
		} else {
			return a.id < b.id;
		}
	}
};

int n, num_tick, num_query;
set<Raffle, CompareNext> s_next;
set<Raffle, CompareLast> s_last;
vector<Raffle> raffles;

int num_bought = 0;
double answer = 0;

void buy_some_ticket() {
	while (s_next.size() && num_bought < num_tick) {
		int which = s_next.rbegin()->id;
		if (raffles[which].buying == raffles[which].size) {
			break;
		}
		s_next.erase(raffles[which]);
		s_last.erase(raffles[which]);

		answer += raffles[which].next_buy;
		num_bought++;
		raffles[which].buying++;
		raffles[which].update();

		s_next.insert(raffles[which]);
		s_last.insert(raffles[which]);
	}

}

int main() {
	scanf("%d %d %d", &n, &num_tick, &num_query);
	answer = num_bought = 0;
	{
		vector<int> p;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			p.push_back(x);
		}
		raffles.clear(); s_next.clear(); s_last.clear();
		for (int i = 0; i < n; i++) {
			int l;
			scanf("%d", &l);
			raffles.push_back(Raffle(p[i], l, i));
			s_next.insert(raffles[i]);
			s_last.insert(raffles[i]);
		}
	}

	buy_some_ticket();

	for (int id_query = 0; id_query < num_query; ++id_query) {
		int type, k;
		scanf("%d %d", &type, &k); k--;
		s_next.erase(raffles[k]);
		s_last.erase(raffles[k]);
		answer -= raffles[k].gain();

		if (s_last.size() && s_last.begin()->buying) {
			int which = s_last.begin()->id;
			s_next.erase(raffles[which]);
			s_last.erase(raffles[which]);
			answer -= raffles[which].last_buy;
			raffles[which].buying--;
			num_bought--;
			raffles[which].update();

			s_next.insert(raffles[which]);
			s_last.insert(raffles[which]);
		}

		if (raffles[k].buying) {
			raffles[k].buying--;
			num_bought--;
		}

		if (type == 1) {
			raffles[k].size++;
		} else {
			raffles[k].size--;
		}

		raffles[k].update();
		answer += raffles[k].gain();
		s_next.insert(raffles[k]);
		s_last.insert(raffles[k]);
//		cout << num_bought << " " << answer << endl;
		buy_some_ticket();
		printf("%.10f\n", answer);
	}
	return 0;
}