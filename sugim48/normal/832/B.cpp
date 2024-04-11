#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;

bool check(string& s, string& t, vector<bool>& a) {
	int N = s.length(), M = t.length();
	if (N - 1 > M) return false;
	int i0 = -1;
	rep(i, N) if (s[i] == '*') i0 = i;
	if (i0 == -1) {
		if (N != M) return false;
		rep(i, N)
			if ((s[i] == t[i]) || (s[i] == '?' && a[t[i] - 'a']));
			else return false;
	}
	else {
		string s1 = s.substr(0, i0);
		string s2 = s.substr(i0 + 1);
		int n1 = s1.length(), n2 = s2.length();
		for (int i = 0; i < n1; i++)
			if ((s1[i] == t[i]) || (s1[i] == '?' && a[t[i] - 'a']));
			else return false;
		for (int i = 0; i < n2; i++)
			if ((s2[i] == t[M - n2 + i]) || (s2[i] == '?' && a[t[M - n2 + i] - 'a']));
			else return false;
		for (int j = n1; j < M - n2; j++)
			if (!a[t[j] - 'a']);
			else return false;
	}
	return true;
}

int main() {
	string good; cin >> good;
	vector<bool> a(26);
	for (char c: good) a[c - 'a'] = true;
	string s; cin >> s;
	int Q; cin >> Q;
	while (Q--) {
		string t; cin >> t;
		printf(check(s, t, a) ? "YES\n" : "NO\n");
	}
}