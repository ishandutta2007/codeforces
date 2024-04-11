#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int B = 8;

char buf[12345678];

string pad(string s) {
	string zeros;
	for(int i = 0; i < 4 - int(s.size()); ++i) {
		zeros += '0';
	}
	return zeros + s;
}

int strlen(char *s) {
	int x;
	for(x = 0; s[x] != '\0'; ++x) 
		;
	return x;
}

void go() {
	vector<string> v;
	vector<string> ans;
	scanf("%s", buf);
	int len = strlen(buf);
	string tmp;
	bool empt = false;
	for(int i = 0; i <= len; ++i) {
		if (i == len || buf[i] == ':') {
			if (tmp != "" || !empt) {
				v.push_back(tmp);
			}
			if (tmp == "") {
				empt = true;
			}
			tmp = "";
		} else {
			tmp += buf[i];
		}
	}
	int k = int(v.size());
	int need = B - k;
	for(int i = 0; i < k; ++i) {
		if (v[i].size() > 0) {
			ans.push_back(pad(v[i]));
		} else {
			for(int j = 0; j <= need; ++j) {
				ans.push_back("0000");
			}
		}
	}
	for(int i = 0; i < 8; ++i) {
		if (i) {
			printf(":");
		}
		printf("%s", ans[i].c_str());
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		go();
	}
}