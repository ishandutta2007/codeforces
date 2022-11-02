#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int max_answer = 0;
vector <int> b_answer;
 
bool check(const vector<int>& tms, const vector <int>& nums, int m, int t) {
        map<int, set<int> > schedule;
 
        bool ok = false;
        for (int i = 0; i < tms.size(); ++i) {
                int beg = tms[i];
                for (int j = 0; j < t; ++j) {
                        schedule[beg + j].insert(nums[i]);
                        if (schedule[beg + j].size() == m) {
                                ok = true;
                        }
                        if (schedule[beg + j].size() > m) {
                                return false;
                        }
                }
        }
        return ok == true;
}
 
void rec(int have, const vector <int>& tms, vector <int>& nums, int m, int t, int u) {
        if (have == tms.size()) {
                if (check(tms, nums, m, t)) {
                        if (u > max_answer) {
                                max_answer = u;
                                b_answer = nums;
                        }
                }
                return;
        }
        for (int i = 1; i <= u; ++i) {
                nums.push_back(i);
                rec(have + 1, tms, nums, m, t, u);
                nums.pop_back();
        }
        nums.push_back(u + 1);
        rec(have + 1, tms, nums, m, t, u + 1);
        nums.pop_back();
}
 
int solve(int m, int t, vector <int> tms) {
        sort(tms.begin(), tms.end());
        vector <int> a;
        max_answer = 0;
        rec(0, tms, a, m, t, 0);
        return max_answer;
}
 
vector <int> gen_times() {
        vector <int> cur;
        for (int i = 0; i < 7; ++i) {
                cur.push_back(rand() % 50);
        }
        sort(cur.begin(), cur.end());
        cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
        return cur;
}

const int maxN = 111000;
int n, m, t;
int a[maxN];
vector < int > add[maxN];
vector < int > slots[maxN];
set < int > del[maxN];

int v[maxN];
int pos[maxN];
int id[maxN];

int solve_Dima(int m, int t, vector < int > a) {
	for (int i = 0; i < maxN; ++i) {
		add[i].clear();
		del[i].clear();
	}
	for (int i = 0; i < a.size(); ++i) {
		add[a[i]].push_back(i);
	}
	int res = 0;
	vector < int > p;
	for (int i = 0; i < m; ++i) {
		p.push_back(i);
	}
	int lastId = -1;
	bool ok = false;
	for (int i = 0; i < maxN; ++i) {
		for (set < int > ::iterator it = del[i].begin(); it != del[i].end(); ++it) {
			p.push_back(*it);
		}

		for (int j = 0; j < add[i].size(); ++j) {
			if (p.size() == 0) {
				ok = true;
				del[pos[lastId]].erase(lastId);
				v[add[i][j]] = id[lastId];
				pos[lastId] = i + t;
				del[i + t].insert(lastId);
			} else {
				lastId = p.back();
				v[add[i][j]] = ++res;
				del[i + t].insert(lastId);
				id[lastId] = res;
				pos[lastId] = i + t;
				p.pop_back();
			}
			if (p.size() == 0) {
				ok = true;
			}
		}
	}
	vector < int > ww;
	for (int i = 0; i < a.size(); ++i) {
		ww.push_back(v[i]);
	}
	if (ok && !check(a, ww, m, t)) {
		cerr << "Fuck" << endl;
	}
	return (ok ? res : 0);
}

void run_test() {
        vector <int> cur = gen_times();
        int m = rand() % 10 + 1;
        int t = rand() % 20 + 1;
        int res1 = solve(m, t, cur);
        int res2 = solve_Dima(m, t, cur);
 
        if (res1 == res2) {
                cerr << "OK" << endl;
        } else {
                cout << res1 << endl;
                /*for (int i = 0; i < b_answer.size(); ++i) {
                        cout << b_answer[i] << endl;
                }*/
                cout << res2 << endl;
                cout << m << " " << t << endl;
                for (int i = 0; i < cur.size(); ++i) {
                        cout << cur[i] << endl;
                }
				solve_Dima(m, t, cur);
				exit(0);
        }
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*int tests = 0;
	while (true) {
		++tests;
			//cerr << tests << endl;
		run_test();
	}*/
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d:%d:%d", &x, &y, &z);
		a[i] = x * 3600 + y * 60 + z;
		add[a[i]].push_back(i);
	}

	int res = 0;
	vector < int > p;
	for (int i = 0; i < m; ++i) {
		p.push_back(i);
	}
	int lastId = -1;
	bool ok = false;
	for (int i = 0; i < maxN; ++i) {
		for (set < int > ::iterator it = del[i].begin(); it != del[i].end(); ++it) {
			p.push_back(*it);
		}
		for (int j = 0; j < add[i].size(); ++j) {
			if (p.size() == 0) {
				ok = true;
				del[pos[lastId]].erase(lastId);
				v[add[i][j]] = id[lastId];
				pos[lastId] = i + t;
				del[i + t].insert(lastId);
			} else {
				lastId = p.back();
				v[add[i][j]] = ++res;
				del[i + t].insert(lastId);
				id[lastId] = res;
				pos[lastId] = i + t;
				p.pop_back();
			}
			if (p.size() == 0) {
				ok = true;
			}
		}
	}

	if (ok) {
		printf("%d\n", res);
		for (int i = 0; i < n; ++i) {
			printf("%d\n", v[i]);
		}
	} else {
		printf("No solution\n");
	}

	return 0;
}