#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 60;
bool visited[MAXN][MAXN][MAXN][MAXN];

int getsuit(char c) {
	switch (c) {
	case 'S': return 0;
	case 'H': return 1;
	case 'D': return 2;
	case 'C': return 3;
	default: return -1;
	}
}
int getrank(char c) {
	switch (c) {
	case 'T': return 10;
	case 'J': return 11;
	case 'Q': return 12;
	case 'K': return 13;
	default: return c - '0';
	}
}	
int conv(string card) {
	int rank = getrank(card[0]);
	int suit = getsuit(card[1]);
	return rank * 4 + suit;
}
bool fits(int a, int b) {
	if (b == -1) {
		return false;
	}
	int ra = a / 4;
	int rb = b / 4;
	int sa = a % 4;
	int sb = b % 4;
	return ra == rb || sa == sb;
}

int ar[MAXN];

bool visit(int n, int a, int b, int c) {
	if (n <= 0) {
		return true;
	}
	if (visited[n][a][b][c]) {
		return false;
	}
	visited[n][a][b][c] = true;
	int d = -1;
	if (n - 3 >= 0) {
		d = ar[n - 3];
	}
	if (fits(a, b)) {
		if (visit(n - 1, a, c, d)) {
			return true;
		}
	}
	if (fits(a, d)) {
		if (visit(n - 1, b, c, a)) {
			return true;
		}
	}
	return false;
}
int N;
char buf[1234];
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%s", buf);
		ar[i] = conv(string(buf));
	}
	int a = ar[N - 1];
	int b = ar[N - 2];
	int c = ar[N - 3];
	bool ans = visit(N - 1, a, b, c);
	if (ans) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}