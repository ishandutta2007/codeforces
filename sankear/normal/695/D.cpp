#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define mt make_tuple
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define rank hurank
#define prev huprev
#define link hulink
#define hash huhash
#define y0 yy0
#define y1 yy1
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (false) cerr
#endif

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const ll MAX_T = ll(2e12) + 100;
const int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct year_t {

	int year, first_week_day;
	ll start_sec;

};

vector<year_t> years;

inline bool is_lip_year(int year) {
	return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

inline int get_month_days(int year, int month) {
	int res = month_days[month];
	if (is_lip_year(year) && month == 1) {
		++res;
	}
	return res;
}

inline void init() {
	ll cur_time = 0;
	int cur_week_day = 3;
	for (int year = 1970; cur_time < MAX_T; ++year) {
		if (year == 2016) {
			cerr << "start_sec = " << cur_time << endl;
		}
		year_t tmp;
		tmp.year = year;
		tmp.first_week_day = cur_week_day;
		tmp.start_sec = cur_time;
		years.pb(tmp);
		for (int month = 0; month < 12; ++month) {
			int days = get_month_days(year, month);
			cur_time += days * 24LL * 60 * 60;
			cur_week_day = (cur_week_day + days) % 7;
		}
	}
	cerr << "sz(years) = " << sz(years) << endl;
}

int pattern_s, pattern_m, pattern_h, pattern_day, pattern_date, pattern_month;

inline bool match(int pattern, int value) {
	return pattern == -1 || pattern == value;
}

inline ll myrand() {
	return ((1LL * rand()) << 32) ^ ((1LL * rand()) << 16) ^ rand();
}

inline void solve() {
	ll t;
	scanf("%lld", &t);
	++t;
	ll start_day_secs = t - t % (24LL * 60 * 60);
	int pos = -1, l = 0, r = sz(years) - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (years[mid].start_sec <= t) {
			pos = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	assert(pos != -1);
	int year = years[pos].year;
	t -= years[pos].start_sec;
	int week_day = years[pos].first_week_day;
	int month = 0;
	for (; month < 12; ++month) {
		int days = get_month_days(year, month);
		ll month_secs = days * 24LL * 60 * 60;
		if (month_secs > t) {
			break;
		}
		t -= month_secs;
		week_day = (week_day + days) % 7;
	}
	assert(month < 12);
	int days = get_month_days(year, month);
	int day = 0;
	for (; day < days; ++day) {
		if (24LL * 60 * 60 > t) {
			break;
		}
		t -= 24LL * 60 * 60;
		week_day = (week_day + 1) % 7;
	}
	assert(day < days);
	int seconds = t % 60;
	t /= 60;
	int minutes = t % 60;
	t /= 60;
	assert(t < 24);
	int hours = t;
	int cur_year = year, cur_month = month, cur_day = day, cur_week_day = week_day;
	bool changed = false;
	//cerr << "start " << year << " " << month << " " << day << endl;
	for (;;) {
		if (match(pattern_month, cur_month)) {
			bool ok = false;
			if (pattern_day != -1 && pattern_date != -1) {
				ok = (match(pattern_day, cur_week_day) || match(pattern_date, cur_day));
			}
			else {
				ok = (match(pattern_day, cur_week_day) && match(pattern_date, cur_day));
			}
			if (ok) {
				//cerr << "check " << cur_year << " " << cur_month << " " << cur_day << endl;
				for (int h = 0; h < 24; ++h) {
					if (!match(pattern_h, h)) {
						continue;
					}
					if (!changed && h < hours) {
						continue;
					}
					for (int m = 0; m < 60; ++m) {
						if (!match(pattern_m, m)) {
							continue;
						}
						if (!changed && h == hours && m < minutes) {
							continue;
						}
						int s;
						if (pattern_s == -1) {
							if (!changed && h == hours && m == minutes) {
								s = seconds;
							}
							else {
								s = 0;
							}
						}
						else {
							s = pattern_s;
							if (!changed && (h == hours && m == minutes && s < seconds)) {
								continue;
							}
						}
						printf("%lld\n", start_day_secs + h * 60LL * 60 + m * 60LL + s);
						return;
					}
				}
			}
		}
		changed = true;
		start_day_secs += 24LL * 60 * 60;
		++cur_day;
		cur_week_day = (cur_week_day + 1) % 7;
		if (cur_day >= get_month_days(cur_year, cur_month)) {
			cur_day = 0;
			++cur_month;
			if (cur_month >= 12) {
				cur_month = 0;
				++cur_year;
				//cerr << "cur_year = " << cur_year << endl;
			}
		}
	}
}

int main() {
	srand(42);
#define TASK "D"
#ifdef LOCAL42
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	init();
	cin >> pattern_s >> pattern_m >> pattern_h >> pattern_day >> pattern_date >> pattern_month;
	if (pattern_month != -1) {
		--pattern_month;
	}
	if (pattern_day != -1) {
		--pattern_day;
	}
	if (pattern_date != -1) {
		--pattern_date;
	}
	int n = 1000;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
		//cerr << "test " << i << endl;
	}
	cerr << "time = " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}