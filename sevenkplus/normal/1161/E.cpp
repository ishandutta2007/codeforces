#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n;

void ask(vector<PII>& a) {
	printf("Q %d", (int) a.size());
	for (auto p : a) printf(" %d %d", p.fi+1, p.se+1);
	puts ("");
	fflush(stdout);
}

bool a[N];
int b[N], L;
bool d[N];
int c[N];

int main() {
	int _;
	cin >> _;
	while (_--) {
		cin >> n;
		if (n == -1) return 0;
		memset(a, 0, sizeof a);

		vector<PII> q1;
		for (int i = 0; i+1 < n; i += 2) q1.pb(mp(i, i+1));
		if (!q1.empty()) ask(q1);
		string s1;
		if (!q1.empty()) cin >> s1;
		for (int i = 0; i+1 < n; i += 2)
			a[i] = (s1[i/2] == '1');

		vector<PII> q2;
		for (int i = 1; i+1 < n; i += 2) q2.pb(mp(i, i+1));
		if (!q2.empty()) ask(q2);
		string s2;
		if (!q2.empty()) cin >> s2;
		for (int i = 1; i+1 < n; i += 2)
			a[i] = (s2[i/2] == '1');

		L = 0;
		for (int i = 0; i < n; i ++)
			if (!a[i]) b[L++] = i;

		vector<PII> q3;
		for (int i = 0; i+2 < L; i ++)
			if (i%4 <= 1) q3.pb(mp(b[i], b[i+2]));
		if (!q3.empty()) ask(q3);
		string s3;
		if (!q3.empty()) cin >> s3;
		for (int i = 0, z = 0; i+2 < L; i ++)
			if (i%4 <= 1) {
				d[i] = (s3[z] == '1');
				z++;
			}

		vector<PII> q4;
		for (int i = 0; i+2 < L; i ++)
			if (i%4 >= 2) q4.pb(mp(b[i], b[i+2]));
		if (!q4.empty()) ask(q4);
		string s4;
		if (!q4.empty()) cin >> s4;
		for (int i = 0, z = 0; i+2 < L; i ++)
			if (i%4 >= 2) {
				d[i] = (s4[z] == '1');
				z++;
			}
		
		for (int i = L-1; i >= 0; i--) {
			if (i == L-1) c[i] = 0; else
			if (i == L-2) c[i] = 1; else {
				if (d[i]) c[i] = c[i+2];
				else c[i] = 3-c[i+1]-c[i+2];
			}
		}

		vector<int> S[3];
		int la = 0;
		for (int i = 0; i < L; i ++) {
			for (int j = la; j <= b[i]; j++)
				S[c[i]].pb(j);
			la = b[i]+1;
		}
		printf("A %d %d %d\n", (int) S[0].size(), (int) S[1].size(), (int) S[2].size());
		for (int k = 0; k < 3; k ++) {
			for (auto j : S[k]) printf("%d ", j+1);
			puts ("");
		}
		fflush(stdout);
	}
	return 0;
}