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

bool check(const string& s) {
        int bal = 0;
        for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') {
                        ++bal;
                } else {
                        --bal;
                }
                if (bal < 0) {
                        return false;
                }
        }
        return bal == 0;
}
 
bool check_rotate(string s) {
        for (int i = 0; i < s.length(); ++i) {
                if (check(s)) {
                        cout << s << endl;
                        return true;
                }
                rotate(s.begin(), s.begin() + 1, s.end());
        }
        return false;
}
 
string gen() {
        int len = rand() % 200 + 1;
        string ret = "";
        for (int i = 0; i < len; ++i) {
                ret += "(";
                ret += ")";
        }
        random_shuffle(ret.begin(), ret.end());
        return ret;
}
 
string gen_random() {
        int len = rand() % 10 + 1;
        string ret = "";
        for (int i = 0; i < len; ++i) {
                if (rand() % 2) {
                        ret += "(";
                } else {
                        ret += ")";
                }
        }
        return ret;
}
 
string solve(string s) {
        char cur = ')' + 1;
        string res = "";
        res += cur;
 
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') {
                        ++cnt1;
                } else {
                        ++cnt2;
                }
        }
 
        string add = "";
        int df = abs(cnt1 - cnt2);
        for (int i = 0; i < df; ++i) {
                if (cnt1 > cnt2) {
                        add += ")";
                } else {
                        add += "(";
                }
        }
 
        for (int i = 0; i < s.length(); ++i) {
                string nw = s;
                rotate(nw.begin(), nw.begin() + i, nw.end());
 
                if (cnt1 > cnt2) {
                        nw = nw + add;
                } else {
                        nw = add + nw;
                }
                if (check(nw)) {
                        res = min(res, nw);
                }
        }
        return res;
}

const int maxN = 1100000;

int c[maxN], p[maxN], q[maxN], cl[maxN], classes, n;
char s[maxN];
int lcp[maxN];

void build_step(int len) {
	if (classes == n) return ;
	for (int i = 0; i < n; i ++) c[i] = 0;

	for (int i = 0; i < n; i ++) q[i] = (p[i] + n - len) % n;
	for (int i = 0; i < n; i ++) c[cl[i]] ++;
	for (int i = 1; i < classes; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[cl[q[i]]] - 1] = q[i], c[cl[q[i]]] --;

	classes = 0;
	q[p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (cl[p[i]] > cl[p[i - 1]]) classes ++; else
			if (cl[(p[i] + len) % n] > cl[(p[i - 1] + len) % n]) classes ++;
		q[p[i]] = classes;
	}
	classes ++;
	for (int i = 0; i < n; i ++) cl[i] = q[i];
}

void build_suffix_array() {
	for (int i = 0; i < 256; i ++) c[i] = 0;
	for (int i = 0; i < n; i ++) c[s[i]] ++;
	for (int i = 1; i < 256; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[s[i]] - 1] = i, c[s[i]] --;

	classes = 0;
	cl[p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (s[p[i]] > s[p[i - 1]]) classes ++;
		cl[p[i]] = classes;
	}
	classes ++;

	int len = 1;
	while (true) {
		build_step(len), len += len;
		if (len >= n) break;
	}
}

int balance[maxN];
int t[8 * maxN];
int value[2 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = value[l];
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

int get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	int A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	int B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return min(A, B);
}

void precalc() {
	for (int i = 0; i < n; ++i) {
		value[i + n] = value[i] = (s[i] == '(' ? 1 : -1);
	}
	for (int i = 1; i < 2 * n; ++i) {
		value[i] += value[i - 1];
	}
	build(1, 0, 2 * n - 1);
	for (int i = 0; i < n; ++i) {
		int score = get(1, 0, 2 * n - 1, i, i + n - 1);
		int shift = (i == 0 ? 0 : value[i - 1]);
		balance[i] = score - shift;
	}
}

char res[2 * maxN];

string solve_Dima(const string &S) {
	n = S.size();
	for (int i = 0; i < n; ++i) {
		s[i] = S[i];
	}
	precalc();
	build_suffix_array();
	int value = 0;
	for (int i = 0; i < n; ++i) {
		value += (s[i] == '(' ? 1 : -1);
	}

	for (int i = 0; i < n; ++i) {
		int score = balance[p[i]];
		if (value < 0) {
			score -= value;
		}

		int m = 0;
		if (score >= 0) {
			string res = "";
			if (value < 0) {
				for (int j = 0; j < (-value); ++j) {
					res += '(';
				}
			}
			for (int j = p[i]; j < p[i] + n; ++j) {
				res += s[j % n];
			}
			if (value > 0) {
				for (int j = 0; j < value; ++j) {
					res += ')';
				}
			}
			return res;
		}
	}
}

void run_test() {
        string cur = gen_random();
        string res1 = solve(cur);
        string res2 = solve_Dima(cur);
        if (res1 == res2) {
                cout << "OK" << endl;
        } else {
                cout << res1 << endl;
                cout << res2 << endl;
                cout << cur << endl;
                exit(0);
        }
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*while (true) {
		run_test();
	}*/

	gets(s);
	n = strlen(s);
	precalc();
	build_suffix_array();

	int value = 0;
	for (int i = 0; i < n; ++i) {
		value += (s[i] == '(' ? 1 : -1);
	}

	for (int i = 0; i < n; ++i) {
		int score = balance[p[i]];
		if (value < 0) {
			score -= value;
		}

		int m = 0;
		if (score >= 0) {
			if (value < 0) {
				for (int j = 0; j < (-value); ++j) {
					res[m++] = '(';
				}
			}
			for (int j = p[i]; j < p[i] + n; ++j) {
				res[m++] = s[j % n];
			}
			if (value > 0) {
				for (int j = 0; j < value; ++j) {
					res[m++] = ')';
				}
			}
			res[m] = 0;
			puts(res);
			return 0;
		}
	}

	return 0;
}