#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char a[1000005], b[1000005];
int A, B;

void go(char *s, int &N) {
	N = strlen(s);
	std::reverse(s, s+N);
	while (N && s[N-1] == '0') N--;
}
void ans(int i) {
	printf("%c\n", (i ? (i > 0 ? '>' : '<') : '='));
	exit(0);
}

int main()
{
	scanf(" %s %s", a, b);
	go(a, A);
	go(b, B);
	if (A < B) ans(-1);
	else if (A > B) ans(1);
	else {
		for (int i = A; i--; ) {
			if (a[i] < b[i]) ans(-1);
			else if (a[i] > b[i]) ans(1);
		}
		ans(0);
	}
}