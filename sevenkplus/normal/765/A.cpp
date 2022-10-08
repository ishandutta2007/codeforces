#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n, A, B;
string s0;

int main() {
	cin >> n >> s0;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		string le = s.substr(0, 3);
		string ri = s.substr(4);
		if (le == s0) A++;
		else B++;
	}
	if (A > B) puts ("contest");
	else puts ("home");
	return 0;
}