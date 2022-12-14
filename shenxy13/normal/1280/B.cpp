#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int r, c;
		scanf("%d %d", &r, &c);
		char rel[r][c];
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) scanf(" %c", &rel[j][k]);
		}
		bool s = true;
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				if (rel[j][k] == 'P') s = false;
			}
		}
		if (s) {
			printf("0\n");
			continue;
		} else s = false;
		bool k = true;
		for (int j = 0; j < r; ++j) {
			if (rel[j][0] == 'P') k = false;
		}
		s = s || k;
		k = true;
		for (int j = 0; j < r; ++j) {
			if (rel[j][c - 1] == 'P') k = false;
		}
		s = s || k;
		k = true;
		for (int j = 0; j < c; ++j) {
			if (rel[0][j] == 'P') k = false;
		}
		s = s || k;
		k = true;
		for (int j = 0; j < c; ++j) {
			if (rel[r - 1][j] == 'P') k = false;
		}
		s = s || k;
		if (s) {
			printf("1\n");
			continue;
		} else s = (rel[0][0] == 'A') || (rel[r - 1][0] == 'A') || (rel[0][c - 1] == 'A') || (rel[r - 1][c - 1] == 'A');
		if (s) {
			printf("2\n");
			continue;
		} else s = false;
		for (int j = 0; j < r; ++j) {
			bool l = true;
			for (int k = 0; k < c; ++k) {
				if (rel[j][k] == 'P') l = false;
			}
			s = s || l;
		}
		for (int j = 0; j < c; ++j) {
			bool l = true;
			for (int k = 0; k < r; ++k) {
				if (rel[k][j] == 'P') l = false;
			}
			s = s || l;
		}
		if (s) {
			printf("2\n");
			continue;
		} else s = false;
		for (int j = 0; j < r; ++j) {
			if (rel[j][0] == 'A' || rel[j][c - 1] == 'A') s = true;
		}
		for (int j = 0; j < c; ++j) {
			if (rel[0][j] == 'A' || rel[r - 1][j] == 'A') s = true;
		}
		if (s) {
			if (r == 1 || c == 1) printf("2\n");
			else printf("3\n");
			continue;
		} else s = false;
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < c; ++k) {
				if (rel[j][k] == 'A') s = true;
			}
		}
		if (s) printf("4\n");
		else printf("MORTAL\n");
	}
	return 0;
}