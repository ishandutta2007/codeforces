#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXC = 300;
int N, K;

char buf[123456];
bool vis[MAXC];

bool go() {
	scanf("%d %s", &K, buf);
	N = strlen(buf);
	for(int i = 0; i < N; ++i) {
		if (buf[i] != '?') {
			if (buf[i] - 'a' >= K) {
				return false;
			}
			vis[buf[i]] = true;
		}
	}
	int free = 0;
	for(int i = 0; i < N; ++i) {
		int comp = N - 1 - i;
		if (comp < i) break;
		if (buf[i] == '?') {
			if (buf[comp] == '?') {
				free++;
			} else {
				buf[i] = buf[comp];
			}
		} else {
			if (buf[comp] == '?') {
				buf[comp] = buf[i];
			} else {
				if (buf[comp] != buf[i]) {
					return false;
				}
			}
		}
	}
	vector<char> need;
	for(char a = 'a'; a <= 'a' + K - 1; ++a) {
		if (!vis[a]) need.push_back(a);
	}
	int numneed = need.size();
	if (numneed > free) return false;
	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if (buf[i] == '?') {
			int comp = N - 1 - i;
			char c = 'a';
			if (free - cnt <= numneed) {
				c = need[numneed - free + cnt];
			}
			buf[i] = buf[comp] = c;
			cnt++;
		}
	}
	buf[N] = 0;
	printf("%s\n", buf);
	return true;
}

int main() {
	if (!go()) {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}