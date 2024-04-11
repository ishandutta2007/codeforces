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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int s[maxN];
bool isOn[maxN];
int n, m;
char c[5];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	memset(s, -1, sizeof(s));
	scanf("%d%d", &n, &m);
	for (int step = 0; step < m; ++step) {
		scanf("%s", &c);
		int t;
		scanf("%d", &t);
		if (c[0] == '-') {
			if (!isOn[t]) {
				printf("Already off\n");
				continue;
			} else {
				for (int i = 1; i * i <= t; ++i) {
					if (t % i == 0) {
						if (i > 1) {
							s[i] = -1;
						}
						if (t / i > 1) {
							s[t / i] = -1;
						}
					}
				}
				printf("Success\n");
				isOn[t] = false;
			}
		} else {
			if (isOn[t]) {
				printf("Already on\n");
			} else {
				int ok = -1;
				for (int i = 1; i * i <= t; ++i) {
					if (t % i == 0) {
						if (i > 1 && s[i] != -1) {
							ok = s[i];
							break;
						}
						if (t / i > 1 && s[t / i] != -1) {
							ok = s[t / i];
							break;
						}
					}
				}
				if (ok != -1) {
					printf("Conflict with %d\n", ok);
				} else {
					printf("Success\n");
					for (int i = 1; i * i <= t; ++i) {
						if (t % i == 0) {
							if (i > 1) {
								s[i] = t;
							}
							if (t / i > 1) {
								s[t / i] = t;
							}
						}
					}
					isOn[t] = true;
				}
			}
		}
	}



	return 0;
}