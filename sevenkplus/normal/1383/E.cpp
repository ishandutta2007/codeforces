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

#define P 1000000007
#define N 1000010

string s;
int n;
vector<int> a;

int f[N];

int ff() {
	if (a.size() == 1) return a[0];
	int m = a.size();
	int T = 1;
	T = (ll)T*(a[0]+1)%P;
	T = (ll)T*(a[m-1]+1)%P;
	f[1] = 1;
	for (int i = 2; i < m; i ++) {
		int u = 0;
		for (int j = i-1; j >= 0; j--) {
			f[i] = (f[i] + (ll)f[j]*(a[i-1]-u+1)%P)%P;
			if (j >= 1) {
				u = max(u, a[j-1]+1);
				if (u > a[i-1]) break;
			}
		}
	}
	int S = 0;
	for (int i = 1; i < m; i ++) {
		(S += f[i]) %= P;
	}
	S = (ll)S*T%P;
	return S;
}

int st[N], sn;

int ss[N];

int ask(int x, int y) {
	return (ss[y]-ss[x]+P)%P;
}

int gg() {
	memset(f, 0, sizeof f);
	if (a.size() == 1) return a[0];
	int m = a.size();
	int T = 1;
	T = (ll)T*(a[0]+1)%P;
	T = (ll)T*(a[m-1]+1)%P;
	f[1] = 1;
	ss[2] = 1;
	for (int i = 2; i < m; i ++) {
		int la = i;
		int u = 0;

		while (sn && a[st[sn-1]-1] < a[i-1]) {
			int j = st[sn-1];
			f[i] = (f[i] + (ll)ask(j, la)*(a[i-1]-u+1)%P)%P;
			la = j;
			u = max(u, a[j-1]+1);
			sn--;
		}

		int j = 1;
		if (sn) j = st[sn-1];
		f[i] = (f[i] + (ll)ask(j, la)*(a[i-1]-u+1)%P)%P;

		// cout << i << " " << f[i] << endl;

		st[sn++] = i;
		ss[i+1] = (ss[i] + f[i])%P;
	}
	int S = 0;
	for (int i = 1; i < m; i ++) {
		(S += f[i]) %= P;
	}
	S = (ll)S*T%P;
	return S;
}

int main() {
	cin >> s;
	// srand(time(NULL));
	// for (int i = 0; i < 20000; i ++) s += (char)('0'+rand()%2);
	// s = "10010";
	// cout << s << endl;

	n = s.length();
	
	int nw = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == '0') {
			(nw += 1) %= P;
		} else {
			a.pb(nw);
			nw = 0;
		}
	}

	a.pb(nw);
	// cout << ff() << endl;
	cout << gg() << endl;

	return 0;
}