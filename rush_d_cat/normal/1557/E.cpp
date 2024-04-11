#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool done = false;
int getdir() {
	char s[9];
	scanf("%s", s);
	string tmp = "";
	for (int i = 0; s[i]; i ++) tmp += s[i];
	if (tmp == "Done") {
		done = true; return 0;
	}
	return mp[tmp];
}
int x = 1, y = 1;
int mov(int dx, int dy) {
	x += dx, y += dy;
	printf("%d %d\n", x, y); fflush(stdout);
	int d = getdir();
	return d;
}
int main() {
	mp["Up-Left"] = 0;
	mp["Up"] = 1;
	mp["Up-Right"] = 2;
	mp["Left"] = 3;
	mp["Right"] = 4;
	mp["Down-Left"] = 5;
	mp["Down"] = 6;
	mp["Down-Right"] = 7;

	int t;
	scanf("%d", &t);
	while (t --) {
		done = false;
		x = 1, y = 2;
		printf("%d %d\n", x, y); fflush(stdout);
		getdir();
		if (done) continue;
		for (;;) {
			bool has = false;
			for (int j = 0; j < 5; j ++) {
				int dd = mov(0, 1);  
				if (done) break;
				if (dd >= 5) mov(1, 0);
				if (done) break;
				if (dd <= 2) has = true;
				if (done) break;
			}
			if (done) break;
			if (has == false) mov(1, 0);
			if (done) break;
			has = false;
			for (int j = 0; j < 5; j ++) {
				int dd = mov(0, -1);
				if (done) break;
				if (dd >= 5) mov(1, 0);
				if (done) break;
				if (dd <= 2) has = true;
			}
			if (done) break;
			if (has == false) mov(1, 0);
			if (done) break;
		}
	}


}