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

int main() {
	string s;
	cin >> s;
	printf("%d\n", (s[s.length()-1]-'0')%2);
	return 0;
}