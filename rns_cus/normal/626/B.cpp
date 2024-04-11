#include <bits/stdc++.h>
using namespace std;

int gas[310], n;
char s[1010];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i ++) {
		gas[s[i]] ++;
	}

	if (gas['B'] == 0 && gas['G'] == 0) {
		puts("R"); return 0; }

	if (gas['B'] == 0 && gas['R'] == 0) {
		puts("G"); return 0; }

	if (gas['R'] == 0 && gas['G'] == 0) {
		puts("B"); return 0; }

	if (gas['B'] == 1 && gas['G'] == 1 && gas['R'] == 0) {
		puts("R"); return 0;
	}

	if (gas['B'] == 1 && gas['R'] == 1 && gas['G'] == 0) {
		puts("G"); return 0;
	}

	if (gas['R'] == 1 && gas['G'] == 1 && gas['B'] == 0) {
		puts("B"); return 0;
	}

	if (gas['B'] && gas['G'] && gas['R']) { puts("BGR"); return 0; }

	int vis = 0;
	if (gas['B'] >= 2) vis ++;
	if (gas['G'] >= 2) vis ++;
	if (gas['R'] >= 2) vis ++;

	if (vis >= 2) { puts("BGR"); return 0; }

	if (gas['B'] >= 2) { puts("GR"); return 0; }
	if (gas['G'] >= 2) { puts("BR"); return 0; }
	if (gas['R'] >= 2) { puts("BG"); return 0; }

	puts("BGR");
}