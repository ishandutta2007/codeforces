#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

#define sz(x) int((x).size())

char buf[1234];

int conv(string days, string &time) {
	int yr, mon, day, hr, min, sec;
	sscanf(days.c_str(), "%d-%d-%d", &yr, &mon, &day);
	sscanf(time.c_str(), "%d:%d:%d", &hr, &min, &sec);
	for(int mo = 1; mo < mon; ++mo) {
		if (mo == 2) {
			day += 29;
		} else if (mo <= 7) {
			if (mo % 2 == 1) {
				day += 31;
			} else {
				day += 30;
			}
		} else {
			if (mo % 2 == 0) {
				day += 31;
			} else {
				day += 30;
			}
		}
	}
	sprintf(buf, "%02d:%02d:%02d", hr, min, sec);
	time = string(buf);
	return ((day * 24 + hr) * 60 + min) * 60 + sec;
}

int main() {
	int M, K;
	scanf("%d %d", &M, &K);
	string a, b;
	bool found = false;
	queue<int> q;
	while (cin >> a >> b) {
		string tmp;
		getline(cin, tmp);
		int p = conv(a, b);
	//	printf("Time: %d\n", p);
		if (sz(q) == K - 1) {
			int f = q.front();
			q.pop();
			if (p - f + 1 <= M) {
				printf("%s %s\n", a.c_str(), b.c_str());
				found = true;
				break;
			}
			q.push(p);
		} else {
			q.push(p);
		}
	}
	if (!found) {
		printf("-1\n");
	}
	return 0;
}