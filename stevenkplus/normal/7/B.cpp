#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 110;
bool taken[MAXN];
int start[MAXN];
int len[MAXN];
bool erased[MAXN];

int curx = 1;
int T, M;
int alloc(int size) {
	int numfree = 0;
	int x;
	for(x = 0; x < M; ++x) {
		if (!taken[x]) numfree++;
		else numfree = 0;
		if (numfree == size) break;
	}
	if (x == M) {
		return -1;
	}
	int s = x - size + 1;
	start[curx] = s;
	len[curx] = size;
	for(int i = s; i < s + size; ++i) {
		taken[i] = true;
	}
//	printf("allocated %d at %d\n", size, s);
	return curx++;
}

bool erase(int x) {
	if (x < 1 || x >= curx || erased[x]) {
		return false;
	}
	erased[x] = true;
	int s = start[x];
	for(int i = s; i < s + len[x]; ++i) {
		taken[i] = false;
	}
//	printf("erased %d from %d\n", len[x], s);
	return true;
}
pii tmp[MAXN];
void defrag() {
	int curstart = 0;
	for(int i = 0; i < curx; ++i) {
		tmp[i] = pii(start[i], i);
	}
	sort(tmp, tmp + curx);
	for(int j = 0; j < curx; ++j) {
		int i = tmp[j].second;
		if (!erased[i]) {
			start[i] = curstart;
			curstart += len[i];
		}
	}
	for(int i = 0; i < M; ++i) {
		taken[i] = i < curstart;
	}
}

int main() {
	cin >> T >> M;
	for(int i = 0; i < T; ++i) {
		string command;
		cin >> command;
		if (command == "defragment") {
			defrag();
		} else {
			int arg;
			cin >> arg;
			if (command == "alloc") {
				int res = alloc(arg);
				if (res == -1) {
					printf("NULL\n");
				} else {
					printf("%d\n", res);
				}
			} else if (command == "erase") {
				if (!erase(arg)) {
					printf("ILLEGAL_ERASE_ARGUMENT\n");
				}
			}
		}
	}
	return 0;
}