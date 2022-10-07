#include <cstdio>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

const int MAXN = 100100;
#define sz(x) int((x).size())
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

typedef unsigned int ui;

ui conv(string ip) {
	ui res = 0;
	int tmp = 0;
	repi(i, ip) {
		if (*i == '.') {
			res *= 256;
			res += tmp;
			tmp = 0;
		} else {
			tmp *= 10;
			tmp += *i - '0';
		}
	}
	res *= 256;
	res += tmp;
	return res;
}

string conv(ui ip) {
	string ret, tmp;
	stringstream ss;
	int msk = (1 << 8) - 1;
	ss << (msk & (ip >> 24));
	ss << ".";
	ss << (msk & (ip >> 16));
	ss << ".";
	ss << (msk & (ip >> 8));
	ss << ".";
	ss << (msk & ip);
	ss >> ret;
	return ret;
}


int N, K;
ui ar[MAXN];

int count(ui subnet) {
	set<ui> myset;
	for(int i = 0; i < N; ++i) {
		myset.insert(subnet & ar[i]);
	}
	return sz(myset);
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		ar[i] = conv(s);
	}

	ui subn = 1 << 31;
	int i = 30;
	while (i > 0 && count(subn) != K) {
		subn += 1 << i;
		--i;
	}
	if (i == 0) printf("-1\n");
	else {
		string ans = conv(subn);
		cout << ans << "\n";
	}
	return 0;
}