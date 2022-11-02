#include <bits/stdc++.h>
using namespace std;

#define N 10

const string me = "BERLAND";
int x, y, cnt, maybe, ax, ay;
string s, t, ene, nme[7];
map<string, int> sr, wn, ls, vis;
bool flag;

bool test(int x, int y) {
	wn[me] += x, ls[ene] += x;
	ls[me] += y, wn[ene] += y;
	int ican = 0;
	for (int i = 0; i < 4; i ++) {
		if (nme[i] == me) continue;
		bool flag = 0;
		if (sr[nme[i]] < sr[me]) flag = 1;
		else if (sr[nme[i]] == sr[me]) {
			if (wn[nme[i]] - ls[nme[i]] < wn[me] - ls[me]) flag = 1;
			else if (wn[nme[i]] - ls[nme[i]] == wn[me] - ls[me]) {
				if (wn[nme[i]] < wn[me]) flag = 1;
				else if (wn[nme[i]] == wn[me]) {
					if (nme[i] > me) flag = 1;
				}
			}
		}
		if (flag) ican ++;
	}
	wn[me] -= x, ls[ene] -= x;
	ls[me] -= y, wn[ene] -= y;
	if (ican >= 2) return 1;
	return 0;
}

int main() {
	for (int i = 0; i < 5; i ++) {
		cin>>s>>t;
		scanf("%d:%d", &x, &y);
		wn[s] += x, wn[t] += y, ls[s] += y, ls[t] += x;
		if (x > y) sr[s] += 3;
		else if (x == y) sr[s] ++, sr[t] ++;
		else sr[t] += 3;
		if (!vis[s]) nme[cnt ++] = s;
		if (!vis[t]) nme[cnt ++] = t;
		vis[s] ++, vis[t] ++;
	}
	for (int i = 0; i < 4; i ++) {
		if (vis[nme[i]] == 2 && nme[i] != me) ene = nme[i];
	}
	sr[me] += 3;
	flag = 0;
	for (int d = 1; d < 100 && !flag; d ++) {
		for (int y = 0; y < 100 && !flag; y ++) {
			if (test(y + d, y)) {
				flag = 1, ay = y, ax = y + d;
			}
		}
	}

	if (flag) printf("%d:%d\n", ax, ay);
	else printf("IMPOSSIBLE\n");
}