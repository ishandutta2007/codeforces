#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int X, A, B, C;
int next() {
	int y = (X * A + B) % C;
	X = y;
	return X;
}

typedef vector<int> vi;
#define pb push_back

const int MAXN = 100;
char names[MAXN][MAXN];

int scores[MAXN];
int ar[MAXN];

bool cmp(const int &a, const int &b) {
	return scores[a] > scores[b];
}

vi bask1, bask2, bask3, bask4;

int rm(vi &v, int i) {
	int tmp = v[i];
	v.erase(v.begin() + i);
	return tmp;
}

int N, s;

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%d", &N);
	s = N / 4;
	scanf("%d %d %d %d", &X, &A, &B, &C);
	for(int i = 0; i < N; ++i) {
		scanf("%s", names[i]);
		scanf("%d", scores + i);
		ar[i] = i;
	}
	sort(ar, ar + N, cmp);
	for(int i = 0; i < s; ++i) {
		bask1.pb(ar[i]);
	}
	for(int i = s; i < 2 * s; ++i) {
		bask2.pb(ar[i]);
	}
	for(int i = 2 * s; i < 3 * s; ++i) {
		bask3.pb(ar[i]);
	}
	for(int i = 3 * s; i < 4 * s; ++i) {
		bask4.pb(ar[i]);
	}
	char groupC = 'A';
	while (s) {
		int r1 = rm(bask1, next() % s);
		int r2 = rm(bask2, next() % s);
		int r3 = rm(bask3, next() % s);
		int r4 = rm(bask4, next() % s);
		s--;
		printf("Group %c:\n%s\n%s\n%s\n%s\n", groupC++, names[r1], names[r2], names[r3], names[r4]);
	}
	return 0;
}