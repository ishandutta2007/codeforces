///	Choe Kwang A

#include <bits/stdc++.h>
using namespace std;
#define N 55

int sco[N], goal[N], dif[N], id[N];
string s[N], team[N];
char txt[N*2], A[N], B[N];
int a, b, n;
map <string, int> mp;

bool cmp(int i, int j) {
	return (sco[i] != sco[j]) ? (sco[i] > sco[j]) : (dif[i] != dif[j]) ? (dif[i] > dif[j]) : goal[i] > goal[j];
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) cin >> s[i], mp[s[i]] = i;
	for (int i = 1; i <= n * (n - 1) / 2; i ++) {
		scanf("%s %d%:%d", txt, &a, &b);
		int len = strlen(txt);
		for (int j = 0; j < len; j ++) if (txt[j] == '-') {
			strcpy(A, txt); A[j] = 0;
			strcpy(B, txt + j + 1);
			break;
		}
		sco[mp[A]] += a > b ? 3 : a == b ? 1 : 0;
		sco[mp[B]] += b > a ? 3 : b == a ? 1 : 0;
		goal[mp[A]] += a, goal[mp[B]] += b;
		dif[mp[A]] += a - b, dif[mp[B]] += b - a;
	}
	for (int i = 1; i <= n; i ++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n / 2; i ++) team[i] = s[id[i]];
	sort(team + 1, team + n / 2 + 1);
	for (int i = 1; i <= n / 2; i ++) cout << team[i] << endl;
	return 0;
}