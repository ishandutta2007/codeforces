#include <cstdio>
#include <string>

using namespace std;

string ends[6] = {"lios", "liala", "etr", "etra", "initis", "inites"};
int types[6] = {0, 1, 2, 3, 4, 5};

const int MAXN = 100100;

bool endswith(string &s, string &e) {
	int k = int(s.size()) - e.size();
	if (k < 0) return false;
	for(int i = k, j = 0; i < int(s.size()); ++i, ++j) {
		if (s[i] != e[j]) return false;
	}
	return true;
}

int type(string s) {
	for(int i = 0; i < 6; ++i) {
		if (endswith(s, ends[i])) {
			return types[i];
		}
	}
	return -1;
}

int ar[MAXN];
char buf[12345678];

bool go() {
	int tot = 0;
	bool noun = false;
	int prv = -1;
	while (scanf("%s", buf) != -1) {
		string s(buf);
		++tot;

		int tmp = type(s);
		if (tmp == -1) return false;

		if (tmp == 2 || tmp == 3) {
			if (noun) return false;
			else noun = true;
		}
		if (tmp < prv) {
			return false;
		}

		if (prv != -1 && prv % 2 != tmp % 2) {
			return false;
		}

		prv = tmp;
	}
	return tot == 1 || noun;
}

int main() {
	if (go()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}