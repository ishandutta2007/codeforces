#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using vi = vector<int>;
void solve();


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	auto start = clock();
#endif
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	cerr << endl << endl << (clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
	return 0;
}

#define int li

const int SECONDS_IN_DAY = 24 * 60 * 60;
const int SECONDS_IN_HOUR = 60 * 60;
const int SECONDS_IN_MINUTE = 60;

bool is_long(int month) {
	return month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11;
}

bool is_vis(int year) {
	if (year % 400 == 0) {
		return true;
	}
	return year % 4 == 0 && year % 100 != 0;
}

int get_month_duration(int year, int month) {
	if (month != 1) {
		return 30 + is_long(month);
	}
	return 28 + is_vis(year);
}

int get_fun(int years) {
	return years / 4 - years / 100 + years / 400;
}

int get_vis_years(int years) {
	return get_fun(years + 1970 - 1) - get_fun(1970 - 1);
}

int get_sum_days(int years) {
	return 365 * years + get_vis_years(years);
}

int get_year(int t) {
	int L = 0, R = 1e8;
	while (L + 1 < R) {
		int M = (L + R) / 2;
		if (get_sum_days(M) * SECONDS_IN_DAY <= t) {
			L = M;
		}
		else {
			R = M;
		}
	}
	return 1970 + L;
}


struct Time {
	int s, m, h, week_day, day, month, year;
	void scan() {
		cin >> s >> m >> h >> week_day >> day >> month;
		if (week_day != -1) {
			--week_day;
		}
		if (month != -1) {
			--month;
		}
		if (day != -1) {
			--day;
		}
		year = -1;
	}
	bool day_ok(const Time& ot) const {
		if (month != -1 && ot.month != month) {
			return false;
		}
		if (day == -1 && week_day == -1) {
			return true;
		}
		return day == ot.day || week_day == ot.week_day;
	}
	int get_ticks() const {
		int res = get_sum_days(year - 1970) * SECONDS_IN_DAY;
		for (int m = 0; m < month; ++m) {
			res += get_month_duration(year, m) * SECONDS_IN_DAY;
		}
		res += day * SECONDS_IN_DAY;
		res += h * SECONDS_IN_HOUR + m * SECONDS_IN_MINUTE + s;
		return res;
	}
	bool all_ok(const Time& ot) const {
		if (!day_ok(ot)) {
			return false;
		}
		if (h != -1 && h != ot.h || m != -1 && ot.m != m || s != -1 && ot.s != s) {
			return false;
		}
		return true;
	}
	void add_day() {
		++day;
		week_day = (week_day + 1) % 7;
		if (day == get_month_duration(year, month)) {
			++month;
			day = 0;
			if (month == 12) {
				++year;
				month = 0;
			}
		}
	}
};

void solve() {
	Time need;
	need.scan();

	int Q;
	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		++t;
		int cur_week_day = (t / SECONDS_IN_DAY + 3) % 7;
		int cur_year = get_year(t);
		t -= get_sum_days(cur_year - 1970) * SECONDS_IN_DAY;
		int cur_month = 0;
		for (; ; ++cur_month) {
			int dur = get_month_duration(cur_year, cur_month) * SECONDS_IN_DAY;
			if (t < dur) {
				break;
			}
			t -= dur;
		}
		int cur_day = t / SECONDS_IN_DAY;
		t %= SECONDS_IN_DAY;
		int cur_hour = t / SECONDS_IN_HOUR;
		t %= SECONDS_IN_HOUR;
		int cur_min = t / SECONDS_IN_MINUTE;
		t %= SECONDS_IN_MINUTE;
		int cur_sec = t;

		Time cur = { cur_sec, cur_min, cur_hour, cur_week_day, cur_day, cur_month, cur_year };

		bool found = false;
		if (need.day_ok(cur)) {
			for (int h = cur_hour; !found && h < 24; ++h) {
				for (int m = (h == cur_hour) ? cur_min : 0; !found && m < 60; ++m) {
					for (int s = (h == cur_hour && m == cur_min) ? cur_sec : 0; !found && s < 60; ++s) {
						Time now = cur;
						now.h = h;
						now.m = m;
						now.s = s;
						if (need.all_ok(now)) {
							cout << now.get_ticks() << "\n";
							found = true;
							break;
						}
					}
				}
			}
		}
		if (found) {
			continue;
		}

		cur.h = cur.m = cur.s = 0;
		cur.add_day();
		for (int it = 0; !found && it < 12 * 10; ++it) {
			if (need.month == -1 || need.month == cur.month) {
				int last_month = cur.month;
				while (cur.month == last_month) {
					if (need.day_ok(cur)) {
						Time ans = cur;
						ans.h = 0;
						ans.m = 0;
						ans.s = 0;
						if (need.h != -1) {
							ans.h = need.h;
						}
						if (need.m != -1) {
							ans.m = need.m;
						}
						if (need.s != -1) {
							ans.s = need.s;
						}
						cout << ans.get_ticks() << "\n";
						found = true;
						break;
					}
					cur.add_day();
				}
				
			}
			else {
				cur.week_day = (cur.week_day + get_month_duration(cur.year, cur.month) - cur.day) % 7;
				cur.day = 0;
				++cur.month;
				if (cur.month == 12) {
					cur.month = 0;
					++cur.year;
				}
			}
		}

		assert(found);
	}

}